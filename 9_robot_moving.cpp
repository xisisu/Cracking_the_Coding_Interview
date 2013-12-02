#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	// it is (x+y)! / x!y!
	int robot_moving1(int x, int y) {
		int val = 1;
		for (int i = x+1; i <= x+y; ++i)
			val *= i;
		for (int i = 1; i <= y; ++i)
			val /= i;
		return val;
	}

	int robot_moving(int x, int y) {
		int table[x+1][y+1];

		for (int i = 0; i <= x; ++i)
			table[i][0] = 1;
		for (int i = 0; i <= y; ++i)
			table[0][i] = 1;

		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				table[i][j] = table[i-1][j] + table[i][j-1];
			}
		}

		return table[x][y];
	}

	// with the bad points
	int robot_moving2(int x, int y, set<pair<int, int> > bad) {
		int table[x+1][y+1];

		for (int i = 0; i <= x; ++i) {
			if (bad.find(make_pair(i, 0)) != bad.end()) {
				while (i <= x) 
					table[i++][0] = 0; 
			} else {
				table[i][0] = 1;
			}
		}
		for (int i = 0; i <= y; ++i) {
			if (bad.find(make_pair(0, i)) != bad.end()) {
				while (i <= x)
					table[0][i++] = 0;
			} else {
				table[0][i] = 1;
			}
		}

		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				if (bad.find(make_pair(i, j)) == bad.end()) {
					table[i][j] = table[i-1][j] + table[i][j-1];
				} else {
					table[i][j] = 0;
				}
			}
		}

		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				if (bad.find(make_pair(i, j)) == bad.end()) {
					table[i][j] = table[i-1][j] + table[i][j-1];
				} else {
					table[i][j] = 0;
				}
			}
		}

		return table[x][y];
	}
};

int main()
{
	Solution sol;

	// for (int i = 1; i <= 5; i++) {
	// 	for (int j = 1; j <= 5; j++) {
	// 		cout << sol.robot_moving(i, j) << " ";
	// 		cout << sol.robot_moving1(i, j) << endl;
	// 	}
	// }

	set<pair<int, int> > bad;
	bad.insert(make_pair(0, 1));
	cout << sol.robot_moving2(2, 2, bad) << endl;


	return 0;
}
