#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution{
public:
	int max_sum(int a[], int n) {
		int res = INT_MIN;
		int sum = 0;

		for (int i = 0; i < n; ++i) {
			sum += a[i];
			if (sum < 0) sum = a[i];
			if (sum > res) res = sum;
		}

		return res;
	}
};

int main() {
	Solution sol;
	int a[] = {2, -8, 3, -2, 4, -10};
	int n = sizeof(a) / sizeof(a[0]);

	cout << sol.max_sum(a, n) << endl;

	return 0;
}