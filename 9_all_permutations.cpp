#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> all_permutations(string data) {
		vector<string> res;
		if (data.size() == 0) { return res; }
		if (data.size() == 1) { res.push_back(data); return res; }

		string tmp = data.substr(1, data.size()-1);
		vector<string> r1 = all_permutations(tmp);

		for (int i = 0; i < r1.size(); ++i) {
			for (int j = 0; j < r1[i].size(); ++j) {
				string cur = r1[i];
				cur.insert(j, 1, data[0]);
				res.push_back(cur);
			}
			res.push_back(r1[i]+data[0]);
		}

		return res;
	}

};

int main()
{
	Solution sol;

	vector<string> res = sol.all_permutations("abc");

	cout << "Total: " << res.size() << endl;

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	return 0;
}
