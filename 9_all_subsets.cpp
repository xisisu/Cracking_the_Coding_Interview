#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > all_subsets(vector<int> data) {
		vector<vector<int> > res;
		vector<int> x;

		int N = 1 << data.size();

		for (int i = 0; i < N; i++) {
			x.clear();
			int j = 0; 
			int k = i;
			while (k > 0) {
				if (k & 0x01) { x.push_back(data[j]); }
				j++;
				k >>= 1;
			}
			sort(x.begin(), x.end());
			res.push_back(x);
		}

		return res;
	}

	vector<vector<int> > all_subsets1(vector<int> data) {
		vector<vector<int> > res;
		vector<int> x;

		if (data.size() == 0) { 
			res.push_back(x);
			return res; 
		}

		int val = data.back();
		data.pop_back();

		vector<vector<int> > r1 = all_subsets1(data);
		for (int i = 0; i < r1.size(); i++) {
			res.push_back(r1[i]);
			r1[i].push_back(val);
			res.push_back(r1[i]);
		}

		return res;
	}
};

int main()
{
	Solution sol;
	vector<int> data;

	for (int i = 1; i < 5; ++i) {
		data.push_back(i);
	}

	vector<vector<int> > res = sol.all_subsets1(data);

	cout << "Total: " << res.size() << endl;

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
