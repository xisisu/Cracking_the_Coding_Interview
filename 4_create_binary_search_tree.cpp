#include <iostream>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#include "4_tree.h"
using namespace std;

class Solution {
public:
	TreeNode * create_binary_search_tree(vector<int> data, int start, int end) {
		if (end < start) { return NULL; }

		int mid = (start+end)/2;

		TreeNode *root = new TreeNode(data[mid]);
		root->left = create_binary_search_tree(data, start, mid-1);
		root->right = create_binary_search_tree(data, mid+1, end);	

		return root;
	}
};

int main()
{
	Solution res;
	vector<int> data;

	for (int i = 0; i < 10; i++) {
		data.push_back(i+1);
		// data.push_back((rand()%100)+1);
	}

	sort(data.begin(), data.end());

	cout << "input: ";
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i] << " ";
	}
	cout << endl;

	TreeNode *root = res.create_binary_search_tree(data, 0, data.size()-1);

	cout << "res: ";
	toString(root);

	return 0;
}
