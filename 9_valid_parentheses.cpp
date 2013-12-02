#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
	// left, right means how many '(' and ')' in the str
	vector<string> valid_parentheses(int n, int left, int right, string str) {
		vector<string> res;
		if (left < right) return res;
		if (left > n || right > n) return res;

		if (left == n && right == n) {
			res.push_back(str);
			return res;
		} 

		vector<string> r1 = valid_parentheses(n, left+1, right, str+"(");
		vector<string> r2 = valid_parentheses(n, left, right+1, str+")");
		for (int i = 0; i < r1.size(); i++) { res.push_back(r1[i]); }
		for (int i = 0; i < r2.size(); i++) { res.push_back(r2[i]); }

		return res;
	}

	vector<string> valid_parentheses(int n) {
		return valid_parentheses(n, 0, 0, "");
	}
};

int main()
{
	Solution sol;
	vector<string> res = sol.valid_parentheses(3);

	cout << "Total: " << res.size() << endl;

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}
