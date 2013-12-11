#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void rotate(int a[], int n, int shift) {
		int b[n];

		for (int i = 0; i < n; ++i)
			b[i] = a[(i+shift)%n];
		for (int i = 0; i < n; ++i)
			a[i] = b[i];

		return;
	}

	int __search(int a[], int left, int right, int x) {
		if (right < left) return -1;

		int mid = (left + right) / 2;
		if (x == a[mid]) return mid;
		
		if (a[left] < a[mid]) {  /* left is normal part */
			if (x >= a[left] && x <= a[mid])
				return __search(a, left, mid-1, x);
			else
				return __search(a, mid+1, right, x);
		} else if (a[left] > a[mid]) {   /* left part is not normal */
			if (x >= a[mid] && x <= a[right])
				return __search(a, mid+1, right, x);
			else
				return __search(a, left, mid-1, x);
		} else if (a[left] == a[mid]) { /* trick part */
			if (a[mid] != a[right]) {
				return __search(a, mid+1, right, x);
			} else {
				int res = __search(a, left, mid-1, x);
				if (res == -1)
					return __search(a, mid+1, right, x);
				else 
					return res;
			}
		}

		return -1;
	}

	int binary_search_in_rotated_array(int a[], int n, int target) {
		return __search(a, 0, n-1, target);
	}
};

int main()
{
	Solution sol;
	int a[20];
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; ++i)
		a[i] = i+1;

	sol.rotate(a, n, 10);

	cout << "before: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	for (int i = 0; i < n; ++i) {
		cout << i << " " << sol.binary_search_in_rotated_array(a, n, i) << endl;
	}

	return 0;
}
