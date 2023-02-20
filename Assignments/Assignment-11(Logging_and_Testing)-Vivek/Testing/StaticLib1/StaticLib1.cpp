#include "pch.h"
#include "framework.h"



	float remind(float n1, float n2) {
		float n3 = n1 / n2;
		float n4 = n1 - (n2 * n3);
		return n4;
	}

	char charat(int n) {
		char str[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
					  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
					  's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
		return str[n - 1];
	}