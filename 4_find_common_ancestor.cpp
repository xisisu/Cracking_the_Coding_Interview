#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	bool find(TreeNode *root, TreeNode *target) {
		if (!target || !root) { return false; }
		if (root == target) { return true; }

		stack<TreeNode *> s;
		TreeNode *cur = root;

		while (cur || !s.empty()) {
			if (cur) {
				s.push(cur);
				cur = cur->left;
			} else {
				cur = s.top();
				if (cur == target) {
					return true;
				}
				s.pop();
				cur = cur->right;
			}
		}

		return false;
	}

	bool find1(TreeNode *root, TreeNode *target) {
		if (!target || !root) { return false; }
		if (root == target) { return true; }

		return find1(root->left, target) || find1(root->right, target);
	}

	TreeNode * find_common_ancestor(TreeNode *root, TreeNode *t1, TreeNode *t2) {
		if (!root || !t1 || !t2) { return NULL; }

		if (find1(root->left, t1) && find1(root->left, t2)) {
			return find_common_ancestor(root->left, t1, t2);
		} else if (find1(root->right, t1) && find1(root->right, t2)) {
			return find_common_ancestor(root->right, t1, t2);
		}

		return root;
	}

	// use post-order
	TreeNode *find_common_ancestor1(TreeNode *root, TreeNode *t1, TreeNode *t2) {
		if (!root || !t1 || !t2) { return NULL; }

		stack<TreeNode *> s;
		set<TreeNode *> path;
		set<TreeNode *> visited;
		s.push(root);
		visited.insert(root);

		while (!s.empty()) {
			TreeNode *cur = s.top();

			if (cur->left && visited.find(cur->left) == visited.end()) {
				visited.insert(cur->left);
				s.push(cur->left);
			} else if (cur->right && visited.find(cur->right) == visited.end()) {
				visited.insert(cur->right);
				s.push(cur->right);
			} else {
				if (cur == t1 || cur == t2) {
					stack<TreeNode *> tmpStack = s;
					if (path.empty()) {
						while (!tmpStack.empty()) {
							path.insert(tmpStack.top());
							tmpStack.pop();
						}
					} else {
						while (!tmpStack.empty()) {
							if (path.find(tmpStack.top()) != path.end()) { return tmpStack.top(); }
							tmpStack.pop();
						}
						return NULL;
					}
				}
				s.pop();
			}
		}

		return NULL;
	}

	// use post-order
	TreeNode *find_common_ancestor2(TreeNode *root, TreeNode *t1, TreeNode *t2) {
		if (!root || !t1 || !t2) { return NULL; }

		stack<TreeNode *> s;
		set<TreeNode *> path;
		s.push(root);
		TreeNode *pre = NULL;

		while (!s.empty()) {
			TreeNode *cur = s.top();

			// continue travel
			if (!pre || pre->left == cur || pre->right = cur) {
				if (cur->left) { s.push(cur->left); }
				else if (cur->right) { s.push(cur->right); }
				else { s.pop(); }
			} 

			// move up from left
			else if (cur->left == pre) {
				if (cur->right) { s.push(cur->right); }
				else { s.pop(); }
			}

			// move up from right
			else if (cur->right == pre) {
				s.pop();
			}

			pre = cur;
		}

		return NULL;
	}



	// use post order traversal!
	TreeNode *find_common_ancestor3(TreeNode *root, TreeNode *t1, TreeNode *t2) {
		if (!root || !t1 || !t2) { return NULL; }

		stack<TreeNode *> s;
		set<TreeNode *> path;
		s.push(root);
		TreeNode *prev = NULL;

		while (!s.empty()) {
			TreeNode *curr = s.top();
			if (!prev || prev->left == curr || prev->right == curr) {
				if (curr->left) { s.push(curr->left); }
				else if (curr->right) { s.push(curr->right); }
			} else if (curr->left == prev) {
				if (curr->right) { s.push(curr->right); }
			} else {
				if (curr == t1 || curr == t2) {
					stack<TreeNode *> tmpStack = s;
					if (path.empty()) {
						while (!tmpStack.empty()) {
							path.insert(tmpStack.top());
							tmpStack.pop();
						}
					} else {
						while (!tmpStack.empty()) {
							if (path.find(tmpStack.top()) != path.end()) {
								return tmpStack.top();
							}
							tmpStack.pop();
						}
						return NULL;
					}
				}
				s.pop();
			}
			prev = curr;
		}

		return NULL;
	}
};


int main()
{
	Solution res;
	vector<int> data;

	for (int i = 0; i < 32; i++) {
		data.push_back(i+1);
		// data.push_back((rand()%100)+1);
	}

	TreeNode *root = generate(data);
	cout << "before: ";
	toString(root);

	TreeNode *t1 = root->right->right;
	TreeNode *t2 = root->right->left;

	TreeNode *com = res.find_common_ancestor1(root, t1, t2);

	if (!com) {
		cout << "No COA" << endl;
	} else {
		cout << com->val << endl;
	}

	return 0;
} 
