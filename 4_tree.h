#include <iostream>
#include <queue>
#include <stack>
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

// toString by bfs
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

void preOrder(TreeNode *root) {
    if (!root) { return; }  
    stack<TreeNode *> s;
    TreeNode *cur = root;

    cout << "pre Order: ";
    while (cur || !s.empty()) {
        if (cur) {
            cout << cur->val << " ";
            if (cur->right) { s.push(cur->right); }
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
        }
    }
    cout << endl;
}

void postOrder(TreeNode *root) {
    if (!root) { return; }
    stack<TreeNode *> s;
    TreeNode * pre = NULL;
    s.push(root);

    cout << "post Order: ";

    while (!s.empty()) {
        TreeNode *cur = s.top();
        if (!pre || pre->left == cur || pre->right == cur) {
            if (cur->left) { s.push(cur->left); }
            else if (cur->right) { s.push(cur->right); }
        } else if (cur->left == pre) {
            if (cur->right) { s.push(cur->right); }
        } else {
            cout << cur->val << " ";
            s.pop();
        }
        pre = cur;
    }
    cout << endl;
}

void inOrder(TreeNode *root) {
    if (!root) { return; }
    stack<TreeNode *> s;
    TreeNode *cur = root;

    cout << "in Order: ";
    while (cur || !s.empty()) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
    cout << endl;
}

void bfsOrder(TreeNode *root) {
    if (!root) { return; }
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *placeHolder = new TreeNode(-1000);
    q.push(placeHolder);

    cout << "bfs Order: " << endl;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();

        if (cur == placeHolder) {
            cout << endl;
            if (q.empty()) { 
                cout << endl;
                return; 
            }
            q.push(placeHolder);
        } else {
            cout << cur->val << " ";
            if (cur->left) { q.push(cur->left); }
            if (cur->right) { q.push(cur->right); }
        }
    }
}

