#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	bool same_tree(TreeNode *t1, TreeNode *t2) {
		if (!t1 && !t2) { return true; }
		if (!t1 || !t2) { return false; }

		if (t1->val != t2->val) { return false; }

		return same_tree(t1->left, t2->left) && same_tree(t1->right, t2->right);
	}

	// t2 is a subtree of t1 or not
	bool decide_subtree(TreeNode *t1, TreeNode *t2) {
		if (!t2 || t1 == t2) { return true; }
		if (!t1) { return false; }

		if (same_tree(t1, t2)) { return true; }

		return decide_subtree(t1->left, t2) || decide_subtree(t1->right, t2);
	}

	vector<int> post_order(TreeNode *root) {
		vector<int> res;
		if (!root) { return res; }

		stack<TreeNode *> s;
		s.push(root);
		TreeNode *pre = NULL;

		while (!s.empty()) {
			TreeNode *cur = s.top();

			if (!pre || pre->left == cur || pre->right == cur) {
				if (cur->left) { s.push(cur->left); }
				else if (cur->right) { s.push(cur->right); }
				else {
					res.push_back(-1);
					res.push_back(-1);
				}
			} else if (cur->left == pre) {
				if (cur->right) { s.push(cur->right); }
				else { res.push_back(-1); }
			} else {
				res.push_back(cur->val);
				s.pop();
			}

			pre = cur;
		}
	}

	// unique post-order by adding NULL pointers
	bool decide_subtree1(TreeNode *t1, TreeNode *t2) {
		if (!t2 || t1 == t2) { return true; }
		if (!t1) { return false; }

		vector<int> s1 = post_order(t1);
		vector<int> s2 = post_order(t2);

		cout << "s1: ";
		for (int i = 0; i < s1.size(); ++i) { cout << s1[i] << " "; }
		cout << endl;

		cout << "s2: ";
		for (int i = 0; i < s2.size(); ++i) { cout << s2[i] << " "; }
		cout << endl;

		// check whether s2 is a substring of s1
		for (int i = 0; i <= s1.size()-s2.size(); ++i) {
			int j = 0;
			while (j < s2.size()) {
				if (s1[i+j] != s2[j]) { break; }
				++j;
			}
			if (j == s2.size()) { return true; }
		}

		return false;
	}
};

int main()
{
	Solution res;
	// int input[] = {5,3,-1,8,7,-1,-1,6,4};
	// int input[] = {1, 3, 3, 2, 1, 2, 1, 4, 7, -1, -1, 4, 7};
	int input[] = {1, 2, -1, 3, -1, 4, -1, 5, -1};

	vector<int> data(input, input+9);

	TreeNode *root = generate(data);
	cout << "input is: ";
	toString(root);

	TreeNode *t1 = root->left;
	TreeNode *t2 = root->left->left;

	cout << res.decide_subtree1(t1, t2) << endl;

	return 0;
}
