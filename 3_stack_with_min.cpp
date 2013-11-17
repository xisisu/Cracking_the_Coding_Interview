#include <iostream>
#include <stack>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
	stack<int> s;
	stack<int> m;

public:
	int pop() {
		if (s.empty()) { return -1; }

		int val = s.top();
		s.pop();

		if (val == m.top()) {
			m.pop();
		}

		return val;
	}

	int top() {
		if (s.empty()) { return -1; }

		return s.top();
	}

	int min() {
		if (m.empty()) { return -1; }

		return m.top();
	}

	int push(int val) {
		if (s.empty()) {
			s.push(val);
			m.push(val);
			return 0;
		}

		if (val <= m.top()) {
			m.push(val);
		}

		s.push(val);
	}
};

int main()
{
	Solution res;

    srand(time(NULL));

	for (int i = 0; i < 50; i++) {
		int val = rand()%100 + 1;
		cout << val << " ";
		res.push(val);
	}
	cout << endl;

	for (int i = 0; i < 50; i++) {
		cout << res.min() << " ";
		res.pop();
	}
	cout << endl;

	return 0;
}
