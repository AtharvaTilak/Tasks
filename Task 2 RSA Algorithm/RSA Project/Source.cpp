#include <iostream>
#include "bigint.h"
#include "grand.h"

using namespace std;

class Clients {
private: 
	string Name1;
	string Name2;
	string message;
};

class RSA {
private:
	string message;
	bigint p, q, e, d, pb, n, phi;
	int l = 9999999999;
public:
	GRand r;
	string getmessage() {
		return message;
	}

	void send() {
		cout << "Enter the message which you want to send to Bob" << endl;
		getline(cin, message);
	}
	void generatePrime() {
		
		p = r.i(100000);
		q = r.i(100000);
		cout << "Generating random prime numbers......" << endl;
		while (big_isPrime(p) == 0) {
			p = r.i(100000);
			while (big_isPrime(p) == 1 && big_isPrime(q) == 0) {
				q = r.i(100000);
		
			}

		}
	}
	void calculate() {
		n = p * q;
		e = r.i(l);
		phi = (p - to_bigint(1)) * (q - to_bigint(1));
		for (bigint i = 0; i < n; i++) {
			bigint temp = big_gcd(e, phi);
			if (temp == to_bigint(1)) {
				break;
			}
			e++;
		}
		cout << "Public Key pb is " << "<" << e << ", " << n << ">" << endl;
		
		bigint a1 = 1, a2 = 0, b1 = 0, b2 = 1, d1 = phi, d2 = e, k, d;
		for (int i = 1; i < phi; i++) {
			k = d1 / d2;
			bigint temp1 = a2;
			a2 = a1 - (a2 * k);
			a1 = temp1;
			bigint temp2 = b2;
			b2 = b1 - (b2 * k);
			b1 = temp2;
			bigint temp3 = d2;
			d2 = d1 - (d2 * k);
			d1 = temp3;
			if (d2 == to_bigint(1)) {
				break;
			}
		}
		if (b2 > phi) {
			d = b2 % phi;
		}
		else if (b2 < to_bigint(0)) {
			d = b2 + phi;
		}
		else {
			d = b2;
		}
		cout << "Private Key is <" << d << ", " << n << ">" << endl;
		cout << "message: " << message << endl;
	}

	bigint encrypt(bigint message) {
		bigint encrpyted_text = 1;
		bigint temp = e % to_bigint(2000);
		while (temp != to_bigint(0)) {
			cout << "temp: " << temp << endl;
			encrpyted_text *= message;
			encrpyted_text %= n;
			temp--;
		}
		return encrpyted_text;
	}

	vector<bigint> encode() {
		vector<bigint> v;
		for (auto& z : message) {
			v.push_back(encrypt((int)z));
		}
		return v;
	}
	bigint decrypt(bigint encrypted_text) {
		bigint temp = d % to_bigint(2000);
		bigint decrypted = 1;
		while (temp != to_bigint(0)) {
			decrypted *= encrypted_text;
			decrypted %= n;
			temp--;
		}
		return decrypted;
	}

	string decode(vector<bigint> g) {
		string s;
		for (auto& num : g)
			to_bigint(s) += decrypt(num);
		return s;
	}
};

int main() {
	RSA rsa = RSA();
	rsa.send();
	rsa.generatePrime();
	rsa.calculate();
	vector<bigint> hidden = rsa.encode();
	cout << "Encoded message is: ";
	for (auto& y : hidden) {
		cout << y;
	}
	cout << "\nDecoded Message is: ";
	cout << rsa.decode(hidden) << endl;
}