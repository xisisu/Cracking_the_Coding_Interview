#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Index {
	int x,y;
};

class Solution {
public:
	bool binary_search_in_matrix(int a[][4], int m, int n, int x) {
		int row = 0, col = n-1;

		while (row < m && col >= 0) {
			printf("(%2d,%2d), val: %2d\n", row, col, a[row][col]);

			if (a[row][col] == x) {
				cout << "find " << x << " at " << row << "," << col << endl;
				return true;
			} else if (a[row][col] > x) {
				if (col > 0) --col;
				else ++row;
			} else {
				if (row < m-1) ++row;
				else --col;
			}
		}

		return false;
	}
};

int main()
{
	Solution sol;
	int a[4][4] = { {15, 20, 70, 85},
					{20, 35, 80, 96},
					{30, 55, 95, 105},
					{40, 80, 120, 120} };

	cout << "input: " << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << setw(2) << a[i][j] << " ";
		cout << endl;
	}


	sol.binary_search_in_matrix(a, 4, 4, 40);
	
	return 0;
}
