#include <iostream>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include "11_sort.h"
using namespace std;

int main()
{
	int a[9];
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++) 	
		a[i] = i+1;

	srand(time(NULL));
	random_shuffle(&a[0], &a[n]);

	cout << "before: ";
	for (int i = 0; i < n; ++i)
		cout << setw(2) << a[i] << " ";
	cout << endl;

	// bubble_sort(a, n);
	// selection_sort(a, n);
	// merge_sort(a, n);
	quick_sort(a, n);
	for (int i = 0; i < 11; ++i)
		cout << i << " " << binary_search(a, n, i) << endl;

	cout << "after : ";
	for (int i = 0; i < n; ++i)
		cout << setw(2) << a[i] << " ";
	cout << endl;

	return 0;
}
