#include <iostream>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	TreeNode * tree_to_list(TreeNode *root) {
		if (!root) 
			return NULL;

		vector<TreeNode *> in_order;

		TreeNode *cur = root;
		stack<TreeNode *> s;
		while (cur || !s.empty()) {
			if (cur) {
				s.push(cur);
				cur = cur->left;
			} else {
				cur = s.top();
				s.pop();
				in_order.push_back(cur);
				cur = cur->right;
			}
		}

		for (int i = 0; i < in_order.size(); ++i) {
			if (i == 0) {
				in_order[i]->left = in_order[in_order.size()-1];
				in_order[i]->right = in_order[i+1];
			} else if (i == in_order.size()-1) {
				in_order[i]->left = in_order[i-1];
				in_order[i]->right = in_order[0];
			} else {
				in_order[i]->left = in_order[i-1];
				in_order[i]->right = in_order[i+1];
			}
		}

		return in_order[0];
	}
};


int main() {
	Solution sol;
	int a[] = {3,2,-1,-1,4,1};
	int n = sizeof(a) / sizeof(a[0]);

	TreeNode *root = generate(a, n);

	toString(root);

	TreeNode *list = sol.tree_to_list(root);
	TreeNode *tmp = list;

	cout << tmp->val;
	tmp = tmp->right;
	while (tmp != list) {
		cout << " " << tmp->val;
		tmp = tmp->right;
	}
	cout << endl;

	return 0;
}