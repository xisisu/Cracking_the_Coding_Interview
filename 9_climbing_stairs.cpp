#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	int climbing_stairs(int n, map<int, int> &m) {
		if (m.find(n) == m.end()) {
			m[n] = climing_stairs(n-1, m) + climing_stairs(n-2, m) + climing_stairs(n-3, m);
		}
		return m[n];
	}

	int climbing_stairs(int n) {
		if (n <= 0) { return 0; }

		map<int, int> m;
		m[1] = 1;
		m[2] = 2;
		m[3] = 3;

		return climing_stairs(n, m);
	}

};

int main()
{
	Solution sol;

	for (int i = 0; i < 10; i++) {
		cout << i << ": " << sol.climbing_stairs(i) << endl;
	}

	return 0;
}
