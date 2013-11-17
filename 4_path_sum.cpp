#include <iostream>
#include <stack>
#include <vector>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	// how to deal with repeated value? should store TreeNode * instead of val
	vector<vector<int> > path_sum1(TreeNode *root, int target) {
		vector<vector<int> > res;
		if (!root) { return res; }

		if (root->val == target) {
			vector<int> tmp;
			tmp.push_back(root->val);
			res.push_back(tmp);
		}

		if (root->left) {
			vector<vector<int> > r1 = path_sum1(root->left, target-root->val);
			for (int i = 0; i < r1.size(); i++) {
				if (r1[i].size() > 0 && r1[i].back() == root->left->val) {
					r1[i].push_back(root->val);
					res.push_back(r1[i]);
				}
			}

			vector<vector<int> > r2 = path_sum1(root->left, target);
			for (int i = 0; i < r2.size(); i++) {
				res.push_back(r2[i]);
			}
		}

		if (root->right) {
			vector<vector<int> > r1 = path_sum1(root->right, target-root->val);
			for (int i = 0; i < r1.size(); i++) {
				if (r1[i].size() > 0 && r1[i].back() == root->right->val) {
					r1[i].push_back(root->val);
					res.push_back(r1[i]);
				}
			}

			vector<vector<int> > r2 = path_sum1(root->right, target);
			for (int i = 0; i < r2.size(); i++) {
				res.push_back(r2[i]);
			}
		}

		return res;
	}

	vector<vector<int> > path_end(stack<TreeNode *> s, int target) {
		vector<vector<int> > res;
		if (s.empty()) { return res; }

		int sum = 0;
		vector<int> tmp;
		while (!s.empty()) {
			tmp.push_back(s.top()->val);
			sum += s.top()->val;
			
			if (sum == target) {
				res.push_back(tmp);
			}
			s.pop();
		}

		return res;
	}

	// use post-order search, try "does this node end with a path of sum?"
	vector<vector<int> > path_sum(TreeNode *root, int target) {
		vector<vector<int> > res;
		if (!root) { return res; }
		stack<TreeNode *> s;
		s.push(root);
		TreeNode *pre = NULL;

		while (!s.empty()) {
			TreeNode *cur = s.top();

			if (!pre || pre->left == cur || pre->right == cur) {
				vector<vector<int> > r1 = path_end(s, target);
				for (int i = 0; i < r1.size(); i++) {
					res.push_back(r1[i]);
				}
				if (cur->left) { s.push(cur->left); }
				else if (cur->right) { s.push(cur->right); }
			} else if (cur->left == pre) {
				if (cur->right) { s.push(cur->right); }
			} else {
				s.pop();
			}

			pre = cur;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	int input[] = {1, 2, -1, 3, -1, 4, -1, 5, -1};
	vector<int> data(input, input+9);

	TreeNode *root = generate(data);
	cout << "input is: ";
	toString(root);

	vector<vector<int> > res = sol.path_sum(root, 7);

	cout << "path is: " << endl;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
