#include <iostream>
#include "2_list.h"
#include <set>
#include <stack>
using namespace std;

class Solution { 
public:
	bool palindrome(List list) {
		if (list.Head() == NULL) { return true; }
		
		List reverse;
		int len = 0;

		Node *cur = list.Head();
		while (cur != NULL) {
			len++;
			reverse.AppendHead(cur->Data());
			cur = cur->Next();
		}

		cur = list.Head();
		Node *rev = reverse.Head();

		int count = 0;
		while (cur != NULL && rev != NULL) {
			if (cur->Data() != rev->Data()) {
				return false;
			}
			if (++count >= len/2) { return true; }
			cur = cur->Next();
			rev = rev->Next();
		}

		if (cur != NULL || rev != NULL) {
			return false;
		}

		return true;
	}

	bool palindrome2(List list) {
		if (list.Head() == NULL) { return true; }
		stack<int> table;

		Node *slow = list.Head();
		Node *fast = list.Head();

		while (fast != NULL && fast->Next() != NULL) {
			table.push(slow->Data());
			slow = slow->Next();
			fast = fast->Next()->Next();
		}
		if (fast != NULL) {
			slow = slow->Next();
		}

		while (!table.empty()) {
			if (table.top() != slow->Data()) { return false; }
			table.pop();
			slow = slow->Next();
		}

		return true;
	}
};

int main()
{
	List even;
	List odd;
	Solution res;

	even.Init(8, 100);
	odd.Init(9, 100);

	List newEven;
	Node *cur = even.Head();
	while (cur != NULL) {
		newEven.Append(cur->Data());
		newEven.AppendHead(cur->Data());
		cur = cur->Next();
	}

	List newOdd;
	newOdd.Append(10);  // generate newOdd with Odd also
	cur = odd.Head();
	while (cur != NULL) {
		newOdd.Append(cur->Data());
		newOdd.AppendHead(cur->Data());
		cur = cur->Next();
	}

	even.toString();
	odd.toString();

	cout << res.palindrome(even) << " ";
	cout << res.palindrome(newEven) << endl;
	cout << res.palindrome(odd) << " ";
	cout << res.palindrome(newOdd) << endl;

	cout << res.palindrome2(even) << " ";
	cout << res.palindrome2(newEven) << endl;
	cout << res.palindrome2(odd) << " ";
	cout << res.palindrome2(newOdd) << endl;

	return 0;
}
