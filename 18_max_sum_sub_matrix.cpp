#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#define SIZE 5

class Solution {
public:
	int find_sum(int a[SIZE][SIZE], int row, int col, int row_len, int col_len) {
		int sum = 0;

		for (int i = row; i <= row + row_len; ++i) {
			for (int j = col; j <= col_len + col; ++j) {
				sum += a[i][j];
			}
		}

		return sum;
	}

	// O(N^6) brute force solution
	int max_sum(int a[SIZE][SIZE]) {
		int sum = INT_MIN;
		int row_idx, row_len, col_idx, col_len;

		for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			for (int x = 1; x < SIZE - i; ++x) {
			for (int y = 1; y < SIZE - j; ++y) {
				int val = find_sum(a, i, j, x, y);
				if (val > sum) {
					sum = val;
					row_idx = i; col_idx = j;
					row_len = x; col_len = y;
				}
			}
			}
		}
		}

		printf("start: (%d, %d), row_len: %d, col_len: %d, sum: %d\n", row_idx, col_idx, row_len, col_len, sum);

		return sum;
	}


/*************************************************/

	void preCompute(int a[SIZE][SIZE], int dp[SIZE][SIZE]) {
		for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (i == 0 && j == 0)
				dp[i][j] = a[i][j];
			else if (i == 0)
				dp[i][j] = dp[i][j-1] + a[i][j];
			else if (j == 0)
				dp[i][j] = dp[i-1][j] + a[i][j];
			else 
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
		}
		}
	}

	int compute(int dp[SIZE][SIZE], int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0) {
			return dp[row2][col2];
		} else if (row1 == 0) {
			return dp[row2][col2] - dp[row2][col1-1];
		} else if (col1 == 0) {
			return dp[row2][col2] - dp[row1-1][col2];
		} else {
			return dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
		}
	}

	// DP solution, reduce to O(N^4)
	int max_sum1(int a[SIZE][SIZE]) {
		int dp[SIZE][SIZE];
		preCompute(a, dp);

		int sum = INT_MIN;
		int row_idx, row_len, col_idx, col_len;		
		for (int row1 = 0; row1 < SIZE; ++row1) {
		for (int row2 = row1; row2 < SIZE; ++row2) {
			for (int col1 = 0; col1 < SIZE; ++col1) {
			for (int col2 = col1; col2 < SIZE; ++col2) {
				int val = compute(dp, row1, col1, row2, col2);
				if (val > sum) {
					sum = val;
					row_idx = row1; col_idx = col1;
					row_len = row2-row1; col_len = col2-col1;
				}
			}
			}
		}
		}

		printf("start: (%d, %d), row_len: %d, col_len: %d, sum: %d\n", row_idx, col_idx, row_len, col_len, sum);

		return sum;
	}






	
};


int main() {
	Solution sol;
	int a[SIZE][SIZE];

	srand(time(NULL));

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			a[i][j] = rand()%10-4;
			cout << setw(2) << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "mas sum is: " << sol.max_sum(a) << endl;

	cout << endl;

	cout << "mas sum is: " << sol.max_sum1(a) << endl;


	return 0;
}