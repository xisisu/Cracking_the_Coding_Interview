#include <iostream>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include "10_sort.h"
using namespace std;

class Solution{
public:
	void merge_two_sorted_array(int a[], int b[], int m, int n) {
		int i = m-1;
		int j = n-1;
		int cur = m+n-1;

		while (i >= 0 && j >= 0) {
			if (a[i] > b[j]) 
				a[cur--] = a[i--];
			else 
				a[cur--] = b[j--];
		}

		while (j >= 0)
			a[j] = b[j--];

		return;
	}
};

int main()
{
	Solution sol;
	int a[20];
	int b[10];
	int m = sizeof(a) / sizeof(a[0]);
	int n = sizeof(b) / sizeof(b[0]);

	for (int i = 0; i < m; ++i)
		a[i] = rand() % 100 + 1;
	for (int i = 0; i < n; ++i)
		b[i] = rand() % 100 + 1;

	quick_sort(a, m-n);
	quick_sort(b, n);

	cout << "a: ";
	for (int i = 0; i < m-n; ++i)
		cout << setw(2) << a[i] << " ";
	cout << endl;
	cout << "b: ";
	for (int i = 0; i < n; ++i)
		cout << setw(2) << b[i] << " ";
	cout << endl;

	sol.merge_two_sorted_array(a, b, m-n, n);

	cout << "c: ";
	for (int i = 0; i < m; ++i)
		cout << setw(2) << a[i] << " ";
	cout << endl;

	return 0;
}
