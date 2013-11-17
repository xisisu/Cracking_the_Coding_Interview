#include <iostream>
#include <stack>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define LIMIT 2

class Solution {
	vector<stack<int> > s;
	vector<int> counter;

public:
	int push(int val) {
		if (counter.empty() || counter.back() == LIMIT) {
			cout << endl << "increase" << endl;

			counter.push_back(0);
			stack<int> newStack;
			s.push_back(newStack);
		} 
		s.back().push(val);
		counter.back()++;
	}

	int pop() {
		if (s.empty()) { return -1; }
		
		while (s.back().empty()) {
			cout << endl << "decrease" << endl;

			s.pop_back();
			counter.pop_back();
			if (s.empty()) { return -1; }
		}
		int val = s.back().top();
		s.back().pop();
		counter.back()--;

		return val;
	}

	int popAt(int num) {
		if (num > counter.size()-1 || counter[num] == 0) { return -1; }

		int val = s[num].top();
		s[num].pop();
		counter[num]--;

		return val;
	}
};

int main()
{
	Solution res;

    srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		int val = rand()%100 + 1;
		res.push(val);
		cout << val << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 10; i++) {
		int val = rand()%5;
		cout << val << " " << res.popAt(val) << endl;
	}
	cout << endl;

	for (int i = 0; i < 20; i++) {
		cout << res.pop() << " ";
	}
	cout << endl;

	return 0;
}
