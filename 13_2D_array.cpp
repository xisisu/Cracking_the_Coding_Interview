#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Solution {
public:
	int ** alloc_2D(int row, int col) {
		int **rowptr;

		rowptr = (int **) malloc(row * sizeof(int *));
		for (int i = 0; i < row; ++i)
			rowptr[i] = (int *) malloc(col * sizeof(int));

		return rowptr;
	}

	void free_2D(int **rowptr, int row) {
		for (int i = 0; i < row; ++i)
			free(rowptr[i]);
		free(rowptr);
	}


	int ** alloc_2D2(int row, int col) {
		int **rowptr;
		int head = row * sizeof(int *);
		int data = row * col * sizeof(int);

		cout << "head: " << head << ", data: " << data << endl;

		rowptr = (int **) malloc(head + data);

		int *base = (int*)(rowptr + row);
		for (int i = 0; i < row; ++i)
			rowptr[i] = base + i * col;

		return rowptr;
	}

	void free_2D2(int **rowptr) {
		free(rowptr);
	}
};

int main() {
	Solution sol;
	int m = 4;
	int n = 5;

	int ** a = sol.alloc_2D2(m, n);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = (i+1)*(j+1);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(2) << a[i][j] << " ";
		cout << endl;
	}

	// free_2D(a, m);
	sol.free_2D2(a);

	return 0;
}
