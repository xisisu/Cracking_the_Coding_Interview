#include <iostream>
#include "2_list.h"
#include <set>
using namespace std;

class Solution { 
public:
	void remove_middle_node(Node *mid) {
		if (mid == NULL) { return; }
		if (mid->Next() == NULL) { mid = NULL; return; }

		mid->SetData(mid->Next()->Data());
		mid->SetNext(mid->Next()->Next());
	}
};

int main()
{
	List list;
	Solution res;

	list.Init(10, 10);

	cout << "before: ";
	list.toString();

	Node *pre = list.Head();
	for (int i = 1; i < 10/2; i++) {
		pre = pre->Next();
	}

	res.remove_middle_node(pre);

	cout << "after: ";
	list.toString();

	return 0;
}
