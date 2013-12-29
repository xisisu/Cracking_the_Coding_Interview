#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution{
public:
	int trailing_zeros(int n) {
		int sum = 0;

		for (int i = 1; i < n; ++i) {
			if (i % 5 == 0) {
				int tmp = i;
				while (tmp % 5 == 0) {
					++sum;
					tmp /= 5;
				}
			}
		}

		return sum;
	}

	int trailing_zeros1(int n) {
		int count = 0;

		for (int i = 5; n / i > 0; i *= 5)
			count += n / i;

		return count;
	}

};

int main() {
	Solution sol;

	for (int i = 0; i < 100; ++i) {
		cout << i << " " << sol.trailing_zeros1(i) << endl;
	}

	return 0;
}
