#include <iostream>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#include "4_tree.h"
#include "2_list.h"
using namespace std;

class Solution {
public:
	vector<vector<TreeNode *> > linked_list_from_tree(TreeNode *root) {
		vector<vector<TreeNode *> > res;
		if (!root) { return res; }

		vector<TreeNode *> cur;
		cur.push_back(root);
		res.push_back(cur);

		while (1) {
			cur.clear();

			for (int i = 0; i < res.back().size(); ++i) {
				if ( res.back()[i]->left ) { cur.push_back(res.back()[i]->left); }
				if ( res.back()[i]->right ) { cur.push_back(res.back()[i]->right); }
			}

			if (cur.size() == 0) { break; }

			res.push_back(cur);
		}

		return res;
	}

	vector<List> linked_list_from_tree1(TreeNode *root) {
		vector<List> res;
		
		if (!root) { return res; }

		queue<TreeNode *> q[2];
		int cur=0;
		q[cur].push(root);

		while (!q[cur].empty()) {
			int nxt = (cur+1)%2;
			List tmpList;

			while (!q[cur].empty()) {
				TreeNode *tmp = q[cur].front();
				q[cur].pop();
				
				tmpList.Append(tmp->val);

				if (tmp->left) { q[nxt].push(tmp->left); }
				if (tmp->right) { q[nxt].push(tmp->right); }
			}

			cur=nxt;
			res.push_back(tmpList);
		}

		return res;
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

	vector<vector<TreeNode *> > list = res.linked_list_from_tree(root);

	for (int i = 0; i < list.size(); ++i) {
		for (int j = 0; j < list[i].size(); ++j) {
			cout << list[i][j]->val << " ";
		}
		cout << endl;
	}

	return 0;
}
