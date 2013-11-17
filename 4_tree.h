#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// process by level
TreeNode * generate(vector<int> data) {
    if (data.size() <= 0) { return NULL; }

    TreeNode *root = new TreeNode(data[0]);
    queue<TreeNode *> q;
    q.push(root);

    int idx = 1;
    while (idx < data.size()) {
        TreeNode *cur = q.front();
        q.pop();

        if (data[idx] != -1) {
            cur->left = new TreeNode(data[idx]);
            q.push(cur->left);
        }
        if (++idx >= data.size()) { return root; }
        if (data[idx] != -1) {
            cur->right = new TreeNode(data[idx]);
            q.push(cur->right);
        }
        ++idx;
    }

    return root;
}

void toString(TreeNode *root) {
    if (root == NULL) {
        cout << "empty" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    cout << root->val << " ";

    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();

        if (cur->left) {
            cout << cur->left->val << " ";
            q.push(cur->left);
        } else {
            cout << "# ";
        }

        if (cur->right) {
            cout << cur->right->val << " ";
            q.push(cur->right);
        } else {
            cout << "# ";
        }
    }

    cout << endl;
}

