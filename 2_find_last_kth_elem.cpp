#include <iostream>
#include "2_list.h"
#include <set>
using namespace std;

class Solution { 
public:
	int find_last_kth_elem(List list, int k) {
		if (k <= 0) { return -1; }

		Node *first = list.Head();
		Node *second = first;

		while (k-- > 0) {
			if (first != NULL) {
				first = first->Next();
			} else {
				return -1;
			}
		}

		while (first != NULL) {
			first = first->Next();
			second = second->Next();
		}

		return second->Data();
	}
};

int main()
{
	List list;
	Solution res;

	list.Init(10, 10);

	cout << "before: ";
	list.toString();

	for (int i = 10; i > 0; i--) {
		cout << res.find_last_kth_elem(list, i) << endl;		
	}


	return 0;
}
