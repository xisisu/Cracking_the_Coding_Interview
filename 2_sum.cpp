#include <iostream>
#include "2_list.h"
#include <set>
using namespace std;

class Solution { 
public:
	List reverse_sum(List a, List b) {
		if (a.Head() == NULL) { return b; }
		if (b.Head() == NULL) { return a; }

		List res;

		int carry = 0;
		Node *a_cur = a.Head();
		Node *b_cur = b.Head();

		while (a_cur != NULL && b_cur != NULL) {
			int val = carry + a_cur->Data() + b_cur->Data();
			res.Append(val%10);
			carry = val / 10;
			a_cur = a_cur->Next();
			b_cur = b_cur->Next();
		}

		while (a_cur != NULL) {
			int val = carry + a_cur->Data();
			res.Append(val%10);
			carry = val / 10;
			a_cur = a_cur->Next();
		}

		while (b_cur != NULL) {
			int val = carry + b_cur->Data();
			res.Append(val%10);
			carry = val / 10;
			b_cur = b_cur->Next();
		}

		if (carry != 0) {
			res.Append(carry);
		}

		return res;

	}

	List sum(List a, List b) {
		if (a.Head() == NULL) { return b; }
		if (b.Head() == NULL) { return a; }

		int a_val = 0;
		Node *a_cur = a.Head();
		while (a_cur != NULL) {
			a_val *= 10;
			a_val += a_cur->Data();
			a_cur = a_cur->Next();
		}

		int b_val = 0;
		Node *b_cur = b.Head();
		while (b_cur != NULL) {
			b_val *= 10;
			b_val += b_cur->Data();
			b_cur = b_cur->Next();
		}

		int res_val = a_val + b_val;
		Node *cur;
		while (res_val != 0) {
			Node *newNode = new Node(res_val%10);
			res_val /= 10;
			newNode->SetNext(cur);
			cur = newNode;
		}

		if (cur == NULL) {
			cur = new Node(0);
		}

		List res;
		res.SetHead(cur);

		return res;
	}
};

int main()
{
	List a, b;
	Solution res;

	a.Init(5, 10);
	b.Init(4, 10);

	cout << "a: ";
	a.toString();
	cout << "b: ";
	b.toString();

	List sum = res.sum(a, b);
	cout << "sum: ";
	sum.toString();

	List reverse_sum = res.reverse_sum(a, b);
	cout << "reverse sum: ";
	reverse_sum.toString();

	return 0;
}
