#include <iostream>
#include "5_bit.h"
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	// extend the problem to include > 1 part
	string double_to_binary(double num) {
		string res; 
		stack<int> s;

		int decimal = int(num);
		while (decimal > 0) {
			s.push(decimal & 0x01);
			decimal >>= 1;
		}
		while (!s.empty()) {
			res += ('0'+s.top());
			s.pop();
		}

		res += '.';

		double frac = num - int(num);
		int counter = 32;
		double power = 0.5;
		while (frac > 0 && counter > 0) {
			counter--;
			if (frac >= power) {
				frac -= power;
				res += "1";
			} else {
				res += "0";
			}
			power /= 2;
		}

		if (counter == 0) { return "ERROR"; }
		else { return res; }
	}
};

int main()
{
	Solution sol;
	
	cout << sol.double_to_binary(15.75) << endl;

	return 0;
}
