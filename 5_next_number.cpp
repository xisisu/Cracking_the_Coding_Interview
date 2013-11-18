#include <iostream>
#include "5_bit.h"
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool contains_one(int num, int one) {
		while (num > 0) {
			if (num & 0x01 == 1) {
				--one;
			}
			
			if (one < 0) return false;
			num /= 2;
		}

		return one==0;
	}

	int count_one(int num) {
		int count = 0;
		while (num > 0) {
			if (num & 0x01 == 1) {
				++count;
			}
			num /= 2;
		}
		return count;
	}

	void next_number1(int num) {
		cout << "input: ";
		toString(num);
		int ones = count_one(num);

		int idx = num-1;
		while (idx > 0) {
			if (contains_one(idx, ones)) {
				cout << "small: ";
				toString(idx);
				break;
			}
			--idx;
		}
		if (idx <= 0) {
			cout << "small does not exist" << endl;
		}

		idx = num+1;
		while (1) {
			if (contains_one(idx, ones)) {
				cout << "large: ";
				toString(idx);
				break;
			}
			++idx;
		}
		cout << endl;

		return;
	}

	// bool contain_zero(int num) {
	// 	while (num > 0) {
	// 		if (num & 0x01 == 0) { return true; }
	// 		else { num /= 2; }
	// 	}
	// 	return false;
	// }

	// bool contain_zero_from(string s, int n) {
	// 	for (int i = n; i >= 0; --i) {
	// 		if (s[i] == '0') { return true; }
	// 	}
	// 	return false;
	// }

	// void next_number(int num) {
	// 	cout << "input: ";
	// 	string s = toString(num);
	// 	string large, small;

	// 	int lowest_one = s.size()-1;
	// 	while (lowest_one >= 0) {
	// 		if (s[lowest_one] == '1') { break; }
	// 		--lowest_one;
	// 	}

	// 	if (lowest_one == s.size()-1) {
	// 		// "11111"
	// 		if (!contain_zero(num)) {
	// 			// large is "10111"
	// 			large = s;
	// 			large.insert(0, "0");
	// 			cout << "next large: " << large << endl;

	// 			// small does not exist
	// 			cout << "next small does not exist" << endl;
	// 		}

	// 		// "10001"
	// 		else {
	// 			// large is "10010"
	// 			large = s;
	// 			int lowest_zero = lowest_one-1;
	// 			while (lowest_zero >= 0) {
	// 				if (large[lowest_zero] == '0') { break; }
	// 				--lowest_zero;
	// 			}
	// 			large[lowest_one] = '0';
	// 			large[lowest_zero] = '1';
	// 			cout << "next large: " << large << endl;

	// 			// small is "1100"
	// 			int lowest_zero = lowest_one-1;
	// 			int next_lowest_one = lowest_one-1;


	// 		}
	// 	} else {
	// 		// "11111000"
	// 		if (!contain_zero_from(s, lowest_one-1)) {
	// 			// large is "100001111"

	// 			// small is "11110100"

	// 		}

	// 		// "111100100"
	// 		else {
	// 			// large is "111101000"

	// 			// small is "111100010"
	// 		}
	// 	}

	// 	return;
	// }
};

int main()
{
	Solution sol;
	
	sol.next_number1(toInt("11111"));
	sol.next_number1(toInt("100110001"));
	sol.next_number1(toInt("111111000"));
	sol.next_number1(toInt("1101100100"));

	return 0;
}
