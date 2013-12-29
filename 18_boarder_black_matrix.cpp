#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10

class Solution {
public:
	bool is_square(bool a[SIZE][SIZE], int row, int col, int size) {
		for (int i = 0; i < size; ++i) {
			if (!a[row+i][col] ||
				!a[row][col+i] ||
				!a[row+size-1][col+i] ||
				!a[row+i][col+size-1])
				return false;
		}

		return true;
	}

	bool find_size(bool a[SIZE][SIZE], int size) {
		int count = SIZE - size + 1;

		for (int i = 0; i < count; ++i) {
			for (int j = 0; j < count; ++j) {
				if (is_square(a, i, j, size)) {
					cout << "find! at (" << i << ", " << j << "), size: " << size << endl;
					return true;
				}
			}
		}

		return false;
	}

	// brute force way
	void find_boarder(bool a[SIZE][SIZE]) {
		for (int i = SIZE; i >= 1; --i) {
			if (find_size(a, i)) 
				return;
		}

		return;
	}

/********************************************************/

	void generate(bool a[SIZE][SIZE], int right[SIZE][SIZE], int below[SIZE][SIZE]) {
		for (int i = SIZE-1; i >= 0; --i) {
			int right_cur = 0;
			int below_cur = 0;
			for (int j = SIZE-1; j >= 0; --j) {
				if (!a[i][j]) {
					right_cur = 0;
					right[i][j] = 0;
				} else {
					++right_cur;
					right[i][j] = right_cur;
				}

				if (!a[j][i]) {
					below_cur = 0;
					below[j][i] = 0;
				} else {
					++below_cur;
					below[j][i] = below_cur;
				}
			}
		}
	}

	bool find_size1(bool a[SIZE][SIZE], int size, int right[SIZE][SIZE], int below[SIZE][SIZE]) {
		int count = SIZE - size + 1;

		for (int i = 0; i < count; ++i) {
			for (int j = 0; j < count; ++j) {
				// topleft: (i,j), topright: (i, j+size); bottomleft: (i+size, j)
				if (right[i][j] >= size &&
					below[i][j] >= size &&
					right[i+size-1][j] >= size &&
					below[i][j+size-1] >= size) {

					// printf("%d %d %d %d %d %d\n", i, j, right[i][j], below[i][j], right[i+size][j], below[i][j+size]);

					cout << "find! at (" << i << ", " << j << "), size: " << size << endl;
					return true;					
				}
			}
		}

		return false;
	}

	// clever way
	void find_boarder1(bool a[SIZE][SIZE]) {
		int right[SIZE][SIZE];
		int below[SIZE][SIZE];

		generate(a, right, below);

		// cout << "right:" << endl;
		// for (int i = 0; i < SIZE; ++i) {
		// 	for (int j = 0; j < SIZE; ++j) {
		// 		cout << setw(2) << right[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		// cout << "below:" << endl;
		// for (int i = 0; i < SIZE; ++i) {
		// 	for (int j = 0; j < SIZE; ++j) {
		// 		cout << setw(2) << below[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		for (int i = SIZE; i >= 1; --i) 
			if (find_size1(a, i, right, below))
				return;
	}
};


int main() {
	Solution sol;
	bool a[SIZE][SIZE];

	srand(time(NULL));

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			a[i][j] = rand()%5 == 0 ? false : true;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	sol.find_boarder(a);

	sol.find_boarder1(a);

	return 0;
}