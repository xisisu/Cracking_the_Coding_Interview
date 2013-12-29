#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution{
public:
	char tic_tac_toe(char a[3][3]) {
		for (int i = 0; i < 3; ++i) {
			// check rows
			if (a[i][0] == a[i][1] && a[i][1] == a[i][2]) 
				return a[i][0];
			// check cols
			if (a[0][i] == a[1][i] && a[0][i] == a[2][i]) 
				return a[0][i];
		}

		// check diagonal
		if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
			return a[0][0];
		// check reverse diagonal
		if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
			return a[0][2];		
	}
};

int main() {
	Solution sol;
	char a[3][3] = { {'x', 'x', 'o'},
					 {'x', 'o', 'o'},
					 {'x', 'o', 'x'} };

	cout << sol.tic_tac_toe(a) << endl;

	return 0;
}