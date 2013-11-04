// Purpose: demonstrate code reuse

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	int digitToValue(char c) {
		if (c >= '0' && c <= '9') return c - '0';
		else if (c >= 'A' && c <= 'Z') return 10 + c - 'A';
		else if (c >= 'a' && c <= 'z') return 10 + c - 'a';
		return -1;
	}
	
	int convertToBase(string number, int base) {
		if (base < 2 || (base > 10 && base != 16)) return -1;
		int value = 0;
		for (int i = number.length()-1; i >= 0; i--) {
			int digit = digitToValue(number[i]);
			if (digit < 0 || digit >= base) {
				return -1;
			}
			int exponent = number.length() - 1 - i;
			value += digit * pow(base, exponent);
		}
		return value;
	}

	bool compare_binary_hex(string binary, string hex) {
		int n1 = convertToBase(binary, 2);
		int n2 = convertToBase(hex, 16);

		// debug use
		// cout << n1 << " " << n2 << endl;

		if (n1 < 0 || n2 < 0) {
			return false;
		} else {
			return n1 == n2;
		}
	}
};

int main()
{
	string binary = "11111111";
	string hex = "ff";
	Solution res;

	cout << res.compare_binary_hex(binary, hex) << endl;

	return 0;
}
