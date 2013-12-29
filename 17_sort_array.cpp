#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
	void sort_array(int a[], int n) {
		int left = 0;
		for (int i = 0; i < n-1; ++i) {
			if (a[i] > a[i+1]) {
				left = i;
				break;
			}
		}

		int right = 0;
		for (int i = n-1; i > 1; --i) {
			if (a[i] < a[i-1]) {
				right = i;
				break;
			}
		}

		int max = 0;
		int min = 1000000;
		for (int i = left+1; i < right; ++i) {
			if (a[i] > max) 
				max = a[i];
			if (a[i] < min)
				min = a[i];
		}

		int left_idx = 0;
		for (int i = 1; i <= left; ++i) {
			if (a[i] > min) {
				left_idx = i-1;
				break;
			}
		}

		int right_idx = n-1;
		for (int i = n-1; i >= right; --i) {
			if (a[i] < max) {
				right_idx = i;
				break;
			}
		}

		cout << left_idx << " " << right_idx << endl;
	}
};

int main() {
	Solution sol;
	int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	int n = sizeof(a) / sizeof(a[0]);

	sol.sort_array(a, n);

	return 0;
}
