#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unordered_set>
#include <windows.h>
#include <string>
#include "bigint.h"

using namespace std;

class procedure {
private:
	int pr;
	int prime;
	int a, b;
	bigint pka, pkb;
	bigint ska, skb;

public:
	void setpr(int n) { pr = n; }
	int getpr() { return pr; }

	void setprime(int n) { prime = n; }
	int getprime() { return prime; }

	void seta(int n) { a = n; }
	int geta() { return a; }

	void setb(int n) { b = n; }
	int getb() { return b; }

	void setpka(int n) { pka = n; }
	bigint getpka() { return pka; }

	void setpkb(int n) { pkb = n; }
	bigint getpkb() { return pkb; }

	void setska(int n) { ska = n; }
	bigint getska() { return ska; }

	void setskb(int n) { skb = n; }
	bigint getskb() { return skb; }

	bigint powerexp(bigint x, bigint y) {
		bigint pow = 1;
		for (int i = 0; i < y; i++) {
			pow = pow * x;
		}
		return pow;
	}

	//Returns true if n is prime
	bool checkPrime(int p)
	{
		if (p <= 1) return false;
		if (p <= 3) return true;

		//this is checked so that we can skip
		//middle five numbers in below loop
		if (p % 2 == 0 || p % 3 == 0 || p % 5 == 0) return false;

		for (int i = 5; i <= p - 3; i = i + 6)
			if (p % i == 0 || p % (i + 2) == 0)
				return false;

		return true;
	}


	int power(int x, unsigned int y, int p)
	{
		int res = 1;	 // Initialize result

		while (y > 0)
		{
			if (y & 1) res = (res * x) % p;

			y = y >> 1;
			x = (x * x) % p;
		}
		return res;
	}

	//This function will be needed in order to calculate primitive root
	void findPrimeFactors(unordered_set<int>& s, int n)
	{
		while (n % 2 == 0)
		{
			s.insert(2);
			n = n / 2;
		}


		for (int i = 3; i <= sqrt(n); i = i + 2)
		{
			while (n % i == 0)
			{
				s.insert(i);
				n = n / i;
			}
		}
		if (n > 2)
			s.insert(n);
	}

	// Function to find smallest primitive root of p
	int primitiveRoot(int p)
	{
		unordered_set<int> s;

		// Check if p is prime or not
		if (checkPrime(p) == false) return -1;
		int phi = p - 1;

		// Find prime factors of phi and store in a set
		findPrimeFactors(s, phi);

		// Check for every number from 2 to phi
		for (int r = 2; r <= phi; r++)
		{
			bool flag = false;
			for (auto it = s.begin(); it != s.end(); it++)
			{
				if (power(r, phi / (*it), p) == 1)
				{
					flag = true;
					break;
				}
			}

			if (flag == false)
				return r;
		}

		// If no primitive root found
		return -1;
	}

	void publicKeys(int p, int q, int a, int b, bigint* pa, bigint* pb) {
		//Calculating public key for Alice
		*pa = powerexp(q, a) % to_bigint(p);
		*pb = powerexp(q, b) % to_bigint(p);
	}

	void secretKeys(bigint pa, bigint pb, int a, int b, int p, bigint* xa, bigint* xb) {
		*xa = powerexp(pb, a) % to_bigint(p);
		*xb = powerexp(pa, b) % to_bigint(p);
	}
};

class User {
private:
	string NameA;
	string NameB;
public:
	void setNameA(string Name) {
		NameA = Name;
	}

	void setNameB(string Name) {
		NameB = Name;
	}

	string getNameA() {
		return NameA;
	}

	string getNameB() {
		return NameB;
	}

	User() {
		cout << "Client 1, enter your name: " << endl;
		cin >> NameA; '\n';
		cout << "Client 2, enter your name: " << endl;
		cin >> NameB; '\n';
	}

	void interact() {
		procedure proc = procedure();
		srand(time(0));
		proc.setprime(rand());
		if (proc.checkPrime(proc.getprime()) == 0) {
			cout << "Creating a random prime number, Please wait......." << endl;
			while (proc.checkPrime(proc.getprime()) == 0) {
				srand(time(0));
				proc.setprime(rand());
				proc.seta(rand() % 1000);
				proc.setb(rand() % 1000);
				if (proc.geta() == 0) while (proc.geta() == 0) {
					proc.seta(rand() % 1000);
				}
				if (proc.getb() == 0) while (proc.getb() == 0) {
					proc.setb(rand() % 1000);
				}
			}
		}
		cout << "Prime number p is " << proc.getprime() << endl;
		proc.setpr(proc.primitiveRoot(proc.getprime()));
		cout << "Primitive root q of p is " << proc.getpr() << endl;
		cout << "Private keys a and b are " << proc.geta() << " & " << proc.geta() << endl;
		bigint pa = proc.getpka();
		bigint pb = proc.getpkb();
		proc.publicKeys(proc.getprime(), proc.getpr(), proc.geta(), proc.getb(), &pa, &pb);
		cout << "Public keys pa and pb are " << pa << " & " << pb << endl;
		bigint xa = proc.getska();
		bigint xb = proc.getskb();
		proc.secretKeys(pa, pb, proc.geta(), proc.getb(), proc.getprime(), &xa, &xb);
		cout << "Secret keys xa and xb are " << xa << " & " << xb << endl;
		if (xa == xb) cout << getNameA() << " and " << getNameB() << " are able to communicate privately" << endl;
	}
};

int main()
{
	User clients = User();
	clients.interact();
	return 0;
}

