#include <iostream>
#include <stdlib.h>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	TreeNode * find_next_node(TreeNode *cur) {
		if (!cur) { return NULL; }

		if (cur->right) {
			TreeNode *res = cur->right;
			while (res->left) {
				res = res->left;
			}
			return res;
		} else {
			cout << "cannot handle this for now" << endl;

			// if (!cur->parent) { 
			// 	return NULL; 
			// } else if (cur == cur->parent->left) {
			// 	return cur->parent;
			// } else if (cur == cur->parent->right) {
			// 	TreeNode *res = cur->parent;
			// 	if (res->parent && res == res->parent->right) {
			// 		res = res->parent;
			// 	}
			// 	return res->parent;
			// }

			return NULL;
		}
	}
};

int main()
{
	Solution res;
	int input[] = {5,3,-1,8,7,-1,-1,6,4};

	vector<int> data(input, input+9);

	TreeNode *root = generate(data);
	cout << "input is: ";
	toString(root);

	TreeNode *cur = root->left;
	TreeNode *nxt = res.find_next_node(cur);

	if (!nxt) {
		cout << "No Next!" << endl;
	} else {
		cout << nxt->val << endl;
	}

	return 0;
}
