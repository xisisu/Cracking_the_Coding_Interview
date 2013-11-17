#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <stdlib.h>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	int findMin(TreeNode *root) {
		if (!root) { return 10000; }

		return min(root->val, min(findMin(root->left), findMin(root->right)));
	}

	int findMax(TreeNode *root) {
		if (!root) { return -10000; }

		return max(root->val, max(findMax(root->left), findMax(root->right)));
	}

	bool check_binary_search_tree(TreeNode *root) {
		if (!root) { return true; }

		if (root->val > findMin(root->right) || root->val < findMax(root->left)) {
			return false;
		}

		return check_binary_search_tree(root->left) && check_binary_search_tree(root->right);
	}

	// recursive approach
	bool check_binary_search_tree1(TreeNode *root, int min, int max) {
		if (!root) { return true; }

		if (root->val <= min || root->val > max) { return false; }

		return check_binary_search_tree1(root->left, min, root->val) && check_binary_search_tree1(root->right, root->val, max);
	}

	bool check_binary_search_tree1(TreeNode *root) {
		return check_binary_search_tree1(root, -10000, 10000);
	}

	// in-order traversal
	bool check_binary_search_tree2(TreeNode *root) {
		if (!root) { return true; }

		vector<int> data;
		stack<TreeNode *> s;
		s.push(root);
		set<TreeNode *> visited;
		visited.insert(root);

		while (!s.empty()) {
			TreeNode *cur = s.top();
			if (cur->left && visited.find(cur->left) == visited.end()) {
				s.push(cur->left);
				visited.insert(cur->left);
			} else if (cur->right) {
				data.push_back(cur->val);
				s.pop();
				s.push(cur->right);
				visited.insert(cur->right);
			} else {
				data.push_back(cur->val);
				s.pop();
			}
		}

		for (int i = 1; i < data.size(); i++) {
			if (data[i] < data[i-1]) { return false; }
		}
		return true;
	}

	bool check_binary_search_tree3(TreeNode *root) {
		if (!root) { return true; }
		int last_val = -10000;

		TreeNode *cur = root;
		stack<TreeNode *> s;	

		while (cur || !s.empty()) {
			if (cur) {
				s.push(cur);
				cur = cur->left;
			} else {
				cur = s.top();
				if (cur->val < last_val) { return false; }
				else { last_val = cur->val; }
				s.pop();
				cur = cur->right;
			}
		}

		return true;
	}
};

int main()
{
	Solution res;
	// int input[] = {2,1,3};
	// int input[] = {1,2,3,4,5,6,7,8,9,10};
	int input[] = {4,2,6,1,-1,5,7};

	vector<int> data(input, input+7);

	TreeNode *root = generate(data);
	cout << "input is: ";
	toString(root);

	cout << res.check_binary_search_tree3(root) << endl;

	return 0;
}
