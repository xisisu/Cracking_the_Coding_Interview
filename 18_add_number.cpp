#include <iostream>
#include <map>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Solution {
public:
	int add_number(int a, int b) {
		if (b == 0) 
			return a;

		int sum = a^b;
		int carry = (a&b) << 1;

		return add_number(sum, carry);
	}
};


int main() {
	int a = 55;
	int b = 10;
	Solution sol;

	cout << sol.add_number(a, b) << endl;

	return 0;
}