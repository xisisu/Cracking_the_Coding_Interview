#include <iostream>
#include "5_bit.h"
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int swap_odd_and_even(int num) {
		int even = 0xaaaaaaaa;
		int odd  = 0x55555555;

		even &= num;
		odd &= num;
		even >>= 1;
		odd <<= 1;

		return even | odd;
	}

	int swap_odd_and_even1(int num) {
		return ( ((num & 0x55555555) >> 1) | ((num & 0xaaaaaaaa) << 1) );
	}

};

int main()
{
	Solution sol;

	for (int i = 10; i < 20; ++i) {
		cout << "input: ";
		toString(i);
		cout << "res  : ";
		toString(sol.swap_odd_and_even(i));
	}

	return 0;
}
