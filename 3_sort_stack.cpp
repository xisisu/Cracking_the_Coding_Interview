#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	void sort_stack(stack<int> &s) {
		stack<int> buf;

		while (!s.empty()) {
			int tmp = s.top();
			s.pop();
			while (!buf.empty() && tmp > buf.top()) {
				s.push(buf.top());
				buf.pop();
			}
			buf.push(tmp);
		}

		while (!buf.empty()) {
			s.push(buf.top());
			buf.pop();
		}
	}
};

int main()
{
	Solution res;
	stack<int> s;

	for (int i = 10; i > 0; --i) {
		s.push(i);
	}

	res.sort_stack(s);

	for (int i = 0; i < 10; ++i) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	return 0;
}
