#include <iostream>
#include "5_bit.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	int m_to_n(string s1, string s2, int i, int j) {
		int n = toInt(s1);
		int m = toInt(s2);
		int mask1 = (0xff << (j+1));
		int mask2 = ((1 << i) - 1);
		int mask = mask1 | mask2;

		cout << "m: ";
		toString(m);

		cout << "n: ";
		toString(n);

		cout << "mask: ";
		toString(mask);

		return (n & mask) | (m << i);
	}
};

int main()
{
	Solution sol;
	
	int res = sol.m_to_n("10000000000", "10011", 2, 6);

	toString(res);

	return 0;
}
