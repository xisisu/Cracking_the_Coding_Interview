#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	void eight_queues(int cur, int n, vector<vector<string> > &res, int table[]) {
		if (cur == n) {
			vector<string> x;
			for (int i = 0; i < n; ++i) {
				string line(n, '.');
				line[table[i]] = 'Q';
				x.push_back(line);
			}
			res.push_back(x);
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (feasible(cur, i, n, table)) {
				table[cur] = i;
				eight_queues(cur+1, n, res, table);
				// table[cur] = -1;   // can safely ignore this line
			}
		}
	}

	bool feasible(int cur, int tmp, int n, int table[]) {
		for (int i = 0; i < cur; ++i) {
			if (table[i] == tmp || table[i]+cur-i == tmp || table[i]-cur+i == tmp) {
				return false;
			}
		}

		return true;
	}

	vector<vector<string> > eight_queues(int n) {
		vector<vector<string> > res;
		int table[n];
		for (int i = 0; i < n; ++i) { table[i] = -1; }

		eight_queues(0, n, res, table);

		return res;
	}
};

int main()
{
	Solution sol;
	vector<vector<string> > res = sol.eight_queues(8);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << endl;
		}
		cout << endl;
	}

	cout << "Total: " << res.size() << endl;

	return 0;
}
