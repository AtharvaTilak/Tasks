#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unordered_set>
#include <windows.h>
#include <string>
#include "bigint.h"

using namespace std;

bigint power(bigint x, bigint y) {
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
	*pa = power(q, a) % to_bigint(p);
	*pb = power(q, b) % to_bigint(p);
}

void secretKeys(bigint pa, bigint pb, int a, int b, int p, bigint* xa, bigint* xb) {
	*xa = power(pb, a) % to_bigint(p);
	*xb = power(pa, b) % to_bigint(p);
}

void interact() {
	srand(time(0));
	int p = rand();
	int a, b;
	if (checkPrime(p) == 0) {
		cout << "Creating a random prime number, Please wait......." << endl;
		while (checkPrime(p) == 0) {
			srand(time(0));
			p = rand();
			a = rand() % 1000;
			b = rand() % 1000;
			if (a == 0) while (a == 0) a = rand() % 1000;
			if (b == 0) while (b == 0) b = rand() % 1000;
		}
	}
	cout << "Prime number p: " << p << endl;
	int q = primitiveRoot(p);
	cout << "Primitive root q of p: " << q << endl;
	cout << "Private keys a and b: " << a << " & " << b << endl;
	bigint pa, pb;
	publicKeys(p, q, a, b, &pa, &pb);
	cout << "Public keys pa and pb: " << pa << " & " << pb << endl;
	bigint xa, xb;
	secretKeys(pa, pb, a, b, p, &xa, &xb);
	cout << "Secret keys xa and xb: " << xa << " & " << xb << endl;
	if (xa == xb) cout << "Alice and Bob are able to communicate privately" << endl;
}

int main()
{
	interact();

	return 0;
}



