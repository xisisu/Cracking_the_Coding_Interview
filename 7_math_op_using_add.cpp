#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
	// return neg(x)
	int neg(int x) {
		int res = 0;
		int d = x < 0 ? 1 : -1;
		while (x != 0) {
			res += d;
			x += d;
		}

		return res;
	}

	// x * y
	int multiply(int x, int y) {
		if (x == 0 || y == 0) { return 0; }
		if (abs(x) < abs(y)) { return multiply(y, x); }

		// now abs(x) always < abs(y)
		for (int i = 0; i < abs(y); ++i) {
			x += x;
		}

		if ( (x < 0 && y < 0) || (x > 0 && y > 0) ) {
			return x;
		} else {
			return neg(x);
		}
	}

	// x - y
	int subtract(int x, int y) {
		return x + neg(y);
	}

	// x / y
	int divide(int x, int y) {
		if (y == 0) { return -1; }
		if (x == 0) { return 0; }


	}

	// x % y
	int mod(int x, int y) {

	}

};

int main()
{
	Solution sol;

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;

		cout << "x: " << x << ", y: " << y << ": ";
		cout << sol.multiply(x, y) << ", ";
		cout << sol.subtract(x, y) << ", ";
		cout << sol.divide(x, y) << ", ";
		cout << sol.mod(x, y);
		
		cout << endl;
	}

	return 0;
}
