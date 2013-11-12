#include <iostream>
#include "2_list.h"
#include <set>
using namespace std;

class Solution { 
public:
	void circular_list(List list) {
		if (list.Head() == NULL) { return; }

		Node *fast = list.Head();
		Node *slow = list.Head();

		slow = slow->Next();
		fast = fast->Next()->Next();

		while (fast != slow) {
			if (fast == NULL || fast->Next() == NULL || slow == NULL) { return; }
			slow = slow->Next();
			fast = fast->Next()->Next();
		}

		fast = list.Head();

		while (fast != slow) {
			fast = fast->Next();
			slow = slow->Next();
		}

		cout << fast->Data() << endl;
	}

	void circular_list2(List list) {
		if (list.Head() == NULL) { return; }

		set<Node *> set;

		Node *cur = list.Head();

		while (1) {
			if (set.find(cur) != set.end()) {
				cout << cur->Data() << endl;
				return ;
			} else {
				set.insert(cur);
				if (cur->Next() == NULL) { 
					return; 
				} else { 
					cur = cur->Next(); 
				}
			}
		}
	}
};

int main()
{
	List list;
	Solution res;

	list.Init(10, 10);

	cout << "before: ";
	list.toString();

	Node *end = list.Head();
	Node *loop;
	int i = 0;
	while (end->Next() != NULL) {
		end = end->Next();
		if (i++ == 7) {
			loop = end;
		}
	}
	end->SetNext(loop);

	cout << "loop start at: " << loop->Data() << endl;

	res.circular_list(list);
	res.circular_list2(list);

	return 0;
}
