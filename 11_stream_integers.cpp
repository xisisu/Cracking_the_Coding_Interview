#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	int leftNode;
	TreeNode(int x) : val(x), left(NULL), right(NULL), leftNode(0) {}
};

class Solution{
private:
	TreeNode *root = NULL;

public:
	// toString by bfs
	void toString() {
	    if (root == NULL) {
	        cout << "empty" << endl;
	        return;
	    }

	    queue<TreeNode *> q;
	    q.push(root);
	    cout << setw(2) << root->val << "(" << root->leftNode << ") ";

	    while (!q.empty()) {
	        TreeNode *cur = q.front();
	        q.pop();

	        if (cur->left) {
			    cout << setw(2) << cur->left->val << "(" << cur->left->leftNode << ") ";
		        q.push(cur->left);
	        } else {
	            cout << "# ";
	        }

	        if (cur->right) {
	    	    cout << setw(2) << cur->right->val << "(" << cur->right->leftNode << ") ";
	            q.push(cur->right);
	        } else {
	            cout << "# ";
	        }
	    }

	    cout << endl;
	}

	void track(int x) {
		if (!root) {
			root = new TreeNode(x);
			return;
		}

		TreeNode *cur = root;

		while (1) {
			if (cur->val > x) {
				cur->leftNode += 1;
				if (cur->left) {
					cur = cur->left;
				} else {
					cur->left = new TreeNode(x);
					return;
				}
			} else {
				if (cur->right) {
					cur = cur->right;
				} else {
					cur->right = new TreeNode(x);
					return;
				}
			}
		}
	}

	int getRank(int x) {
		int res = 0;
		TreeNode *cur = root;

		while (cur) {
			if (cur->val == x) { 
				return res + cur->leftNode; 
			} else if (cur->val > x) {
				cur = cur->left;
			} else {
				res += 1;
				res += cur->leftNode;
				cur = cur->right; 
			}
		}

		return res;
	}	

	void run(int a[], int n) {
		for (int i = 0; i < n; ++i) {
			track(a[i]);
			cout << setw(2) << a[i] << " " << getRank(a[i]) << endl;
		}
		
		toString();
	}
};


int main()
{
	Solution sol;
	int a[10];
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; ++i)
		a[i] = i+1;

	random_shuffle(&a[0], &a[n]);

	cout << "input: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	sol.run(a, n);

	return 0;
}
