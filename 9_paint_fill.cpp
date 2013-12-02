#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void paint_fill(int data[6][6], int n, int m, int x, int y, int newval) {
		if (n <= 0 || m <= 0 || x < 0 || y < 0 || x >= n || y >= m) { return; }

		int oldval = data[x][y];
		data[x][y] = newval;

		if (x > 0 && data[x-1][y] == oldval)
			paint_fill(data, n, m, x-1, y, newval);
		if (y > 0 && data[x][y-1] == oldval)
			paint_fill(data, n, m, x, y-1, newval);
		if (x < n-1 && data[x+1][y] == oldval)
			paint_fill(data, n, m, x+1, y, newval);
		if (y < m-1 && data[x][y+1] == oldval)
			paint_fill(data, n, m, x, y+1, newval);

		return;
	}
};

int main()
{
	Solution sol;
	int data[6][6] = { {5,5,5,5,5,5},
		 			   {5,1,1,1,1,5},
	 				   {5,1,3,3,1,5},
					   {5,1,3,3,1,5},
					   {5,1,1,1,1,5},
					   {5,5,5,5,5,5}};

	cout << "Before" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j)
			cout << data[i][j] << " ";
		cout << endl;
	}

	sol.paint_fill(data, 6, 6, 1, 1, 0);

	cout << "After" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j)
			cout << data[i][j] << " ";
		cout << endl;
	}

	return 0;
}
