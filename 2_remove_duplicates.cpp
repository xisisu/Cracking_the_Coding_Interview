#include <iostream>
#include "2_list.h"
#include <set>
using namespace std;

class Solution { 
public:
	void removeDuplicate(List list) {
		Node *pre = list.Head();
		if (pre == NULL || pre->Next() == NULL) {
			return;
		}

		set<int> table;
		table.insert(pre->Data());

		while(pre->Next() != NULL) {
			if (table.find(pre->Next()->Data()) == table.end()) {
				table.insert(pre->Next()->Data());
				pre = pre->Next();
			} else {
				pre->SetNext(pre->Next()->Next());
			}
		}
	}

	void removeDuplicate2(List list) {
		Node *pre = list.Head();
		if (pre == NULL || pre->Next() == NULL) {
			return;
		}

		while (pre != NULL) {
			Node *cur = pre;
			while (cur->Next() != NULL) {
				if (cur->Next()->Data() == pre->Data()) {
					cur->SetNext(cur->Next()->Next());
				} else {
					cur = cur->Next();
				}
			}
			pre = pre->Next();
		}
	}
};

int main()
{
	List list;
	Solution res;

	list.Init(100, 10);

	cout << "before: ";
	list.toString();

	res.removeDuplicate2(list);

	cout << "after: ";
	list.toString();

	return 0;
}
