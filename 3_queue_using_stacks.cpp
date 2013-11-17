#include <iostream>
#include <stack>
using namespace std;

class Solution {
	stack<int> in;
	stack<int> out;
public:
	void enqueue(int val) {
		in.push(val);
	}

	int dequeue() {
		if (in.empty() && out.empty()) {
			return -1;
		}

		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}

		int val = out.top();
		out.pop();

		return val;
	}
};

int main()
{
	Solution res;

	for (int i = 0; i < 10; ++i) {
		res.enqueue(i);
	}

	for (int i = 0; i < 10; ++i) {
		cout << res.dequeue() << " ";
	}
	cout << endl;

	return 0;
}
