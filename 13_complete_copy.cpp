#include <iostream>
#include <map>
using namespace std;

struct Node {
	int val;
	Node * p1;
	Node * p2;
	Node(int d) : val(d), p1(NULL), p2(NULL) {};
};

Node * complete_copy(Node *cur, map<Node *, Node *> nodeMap) {
	if (!cur) 
		return NULL;

	if (nodeMap.find(cur) != nodeMap.end()) 
		return nodeMap.find(cur)->second;

	Node * node = new Node(cur->val);
	nodeMap[cur] = node;
	node->p1 = complete_copy(cur->p1, nodeMap);
	node->p2 = complete_copy(cur->p2, nodeMap);

	return node;
}

Node * complete_copy(Node *cur) {
	map<Node *, Node *> nodeMap;
	return complete_copy(cur, nodeMap);
}

int main() {
	Node *root = new Node(1);
	root->p1 = new Node(2);
	root->p2 = new Node(3);

	Node *copy = complete_copy(root);

	cout << root->val << " " << root->p1->val << " " << root->p2->val << endl;
	cout << copy->val << " " << copy->p1->val << " " << copy->p2->val << endl;

	root->val = 5;
	cout << endl;

	cout << root->val << " " << root->p1->val << " " << root->p2->val << endl;
	cout << copy->val << " " << copy->p1->val << " " << copy->p2->val << endl;

	return 0;
}
