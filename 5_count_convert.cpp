#include <iostream>
#include "5_bit.h"
#include <string>
#include <stack>
using namespace std;

class Solution {
public:

	int count_ones(int num) {
		int count = 0;
		while (num > 0) {
			if (num & 0x01 == 1) { count++; }
			num /= 2;
		}
		return count;
	}

	int count_convert(int m, int n) {
		int x = m | n;
		int y = m & n;
		int z = x-y;

		cout << "m: ";
		toString(m);
		cout << "n: ";
		toString(n);
		cout << "z: ";
		toString(z);

		return count_ones(z);
	}

	int count_convert1(int m, int n) {
		int count = 0;
		for (int c = m ^ n; c != 0; c >>= 1) {
			count += c&1;
		}
		return count;
	}

	int count_convert2(int m, int n) {
		int count = 0;
		for (int c = m ^ n; c != 0; c &= (c-1)) {
			++count;
		}
		return count;
	}

};

int main()
{
	Solution sol;

	cout << sol.count_convert(31, 14) << endl;
	cout << sol.count_convert1(31, 14) << endl;
	cout << sol.count_convert2(31, 14) << endl;

	return 0;
}
