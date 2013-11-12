#include <iostream>
#include "2_list.h"
#include <set>
using namespace std;

class Solution { 
public:
	void partition_list(List &list, int x) {
		if (list.Head() == NULL) { return; }

		List small;
		List large;

		Node *pre = list.Head();

		while (pre != NULL) {
			if (pre->Data() <= x) {
				small.Append(pre->Data());
			} else {
				large.Append(pre->Data());
			}
			pre = pre->Next();
		}

		if (small.Head() != NULL) {
			pre = small.Head();
			while (pre->Next() != NULL) {
				pre = pre->Next();
			}
			pre->SetNext(large.Head());

			list.SetHead(small.Head());
		} else {
			list.SetHead(large.Head());
		}
	}
};

int main()
{
	List list;
	Solution res;

	list.Init(20, 100);

	cout << "before: ";
	list.toString();

	res.partition_list(list, 50);

	cout << "after: ";
	list.toString();

	return 0;
}
