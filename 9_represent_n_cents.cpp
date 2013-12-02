#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int represent_n_cents1(int n, int denom) {
		int next_denom = 0;
		switch (denom) {
		case 25:
			next_denom = 10;
			break;
		case 10:
			next_denom = 5;
			break;
		case 5:
			next_denom = 1;
			break;
		case 1:
			return 1;
		}

		int ways = 0;
		for (int i = 0; i * denom <= n; ++i) {
			ways += represent_n_cents1(n-i*denom, next_denom);
		}

		return ways;
	}

	vector<vector<int> > represent_n_cents(int n, int denom, vector<int> cur) {
		vector<vector<int> > res;

		int next_denom = 0;
		switch (denom) {
		case 25:
			next_denom = 10;
			break;
		case 10:
			next_denom = 5;
			break;
		case 5:
			next_denom = 1;
			break;
		case 1:
			for (int i = 0; i < n; i++) {
				cur.push_back(1);
			}
			res.push_back(cur);
			return res;
		}

		for (int i = 0; i * denom <= n; ++i) {
			if (i != 0) { cur.push_back(denom); }
			vector<vector<int> > r1 = represent_n_cents(n-i*denom, next_denom, cur);
			for (int j = 0; j < r1.size(); ++j) {
				res.push_back(r1[j]);
			}
		}

		return res;
	}

	vector<vector<int> > represent_n_cents(int n) {
		vector<int> x;
		return represent_n_cents(n, 25, x);
	}


	// many repeated elements, should get rid of them!!
	// has 25 cents, 10 cents, 5 cents, 1 cent
	vector<vector<int> > represent_n_cents2(int n) {
		vector<vector<int> > res;
		if (n == 0) { 
			vector<int> x;
			res.push_back(x);
			return res; 
		}

		if (n >= 25) {
			vector<vector<int> > r1 = represent_n_cents(n-25);
			for (int i = 0; i < r1.size(); ++i) {
				r1[i].push_back(25);
				sort(r1[i].begin(), r1[i].end());
				res.push_back(r1[i]);
			}
		}

		if (n >= 10) {
			vector<vector<int> > r1 = represent_n_cents(n-10);
			for (int i = 0; i < r1.size(); ++i) {
				r1[i].push_back(10);
				sort(r1[i].begin(), r1[i].end());
				res.push_back(r1[i]);
			}
		}

		if (n >= 5) {
			vector<vector<int> > r1 = represent_n_cents(n-5);
			for (int i = 0; i < r1.size(); ++i) {
				r1[i].push_back(5);
				sort(r1[i].begin(), r1[i].end());
				res.push_back(r1[i]);
			}
		}

		if (n >= 1) {
			vector<vector<int> > r1 = represent_n_cents(n-1);
			for (int i = 0; i < r1.size(); ++i) {
				r1[i].push_back(1);
				sort(r1[i].begin(), r1[i].end());
				res.push_back(r1[i]);
			}
		}

		return res;
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > res = sol.represent_n_cents(26);

	cout << "Total: " << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Total: " << sol.represent_n_cents1(26, 25) << endl;
 
	return 0;
}
