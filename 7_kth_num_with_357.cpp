#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
	int kth_num_with_357(int k) {
		queue<int> q[3];

		q[0].push(3);
		q[1].push(5);
		q[2].push(7);

		for (int i = 1; i < k; ++i) {
			int j;
			if (q[0].front() < min(q[1].front(), q[2].front())) {
				j = 0;
			} else {
				j = q[1].front() < q[2].front() ? 1 : 2;
			}

			int val = q[j].front();
			q[j].pop();

			if (j == 0) {
				q[0].push(val*3);
				q[1].push(val*5);
				q[2].push(val*7);
			} else if (j == 1) {
				q[1].push(val*5);
				q[2].push(val*7);
			} else {
				q[2].push(val*7);
			}
		}

		return q[0].front() < min(q[1].front(), q[2].front()) ? q[0].front() : min(q[1].front(), q[2].front());
	}
};

int main()
{
	Solution sol;

	for (int i = 1; i <= 10; i++) {
		cout << i << ": " << sol.kth_num_with_357(i) << endl;
	}

	return 0;
}
