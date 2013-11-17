#include <iostream>
#include <queue>
#include <stdlib.h>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	int height(TreeNode *root) {
		if (!root) { return 0; }
		return max(height(root->left), height(root->right)) + 1;
	}

	bool check_balanced(TreeNode *root) {
		if (!root) { return true; }

		if ( abs(height(root->left) - height(root->right)) > 1 ) {
			return false;
		}

		return check_balanced(root->left) && check_balanced(root->right);
	}

	int height1(TreeNode *root) {
		if (!root) { return 0; }

		int leftHeight = height1(root->left);
		if (leftHeight == -1) {
			return -1;
		}
		int rightHeight = height1(root->right);
		if (rightHeight == -1) {
			 return -1;
		}

		if ( abs(leftHeight - rightHeight) > 1) {
			return -1;
		} else {
			return max(leftHeight, rightHeight) + 1;
		}
	}

	bool check_balanced1(TreeNode *root) {
		if (height1(root) == -1) {
			 return false;
		} else {
			return true;
		}
	}


	bool check_balanced2(TreeNode *root) {
		if (!root) { return true; }

		queue<TreeNode *> q[2];
		int cur = 0;
		q[cur].push(root);

		int layer = 0;
		int hole = 0;
		while (!q[cur].empty()) {
			int nxt = (cur+1)%2;

			if (hole == true && !q[cur].empty())

			while (!q[cur].empty()) {
				TreeNode *tmp = q[cur].front();
				q[cur].pop();
			
				if (tmp->left) {
					q[nxt].push(tmp->left);
				} else {
					if (hole == 0) {
						hole = layer;
					} else {
						if (layer > hole) {
							return false;
						}
					}
				}

				if (tmp->right) {
					q[nxt].push(tmp->right);
				} else {
					if (hole == 0) {
						hole = layer;
					} else {
						if (layer > hole) {
							 return false;
						}
					}
				}
			}

			cur = nxt;
			layer++;
		}

		return true;
	}
};

int main()
{
	Solution res;
	int input[] = {3,2,-1,-1,4,1};

	vector<int> data(input, input+6);

	TreeNode *root = generate(data);
	cout << "input is: ";
	toString(root);

	cout << res.check_balanced1(root) << endl;

	return 0;
}
