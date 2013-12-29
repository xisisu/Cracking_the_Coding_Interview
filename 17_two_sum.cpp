#include <iostream>
#include <map>
#include <cstdlib>

#include <iomanip>
using namespace std;

class Solution {
public:
	int two_sum(int a[], int n, int target) {
		map<int, int> m;

		for (int i = 0; i < n; ++i) {
			int want = target - a[i];
			if (m.find(want) != m.end()) {
				cout << setw(2) << a[i] << " " << setw(2) << want << endl;
				--m[want];
				if (m[want] == 0)
					m.erase(want);
			}

			++m[a[i]];
		}

		return 0;
	}
};


int main() {
	int a[100];
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 100 + 1;
		cout << setw(2) << a[i] << " ";
	}
	cout << endl;

	Solution sol;

	cout << "find: " << endl;
	sol.two_sum(a, n, 100);

	return 0;
}