#include <iostream>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
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
			} else {
				++m[a[i]];
			}
		}

		return 0;
	}

	int two_sum_1(int a[], int n, int target) {
		vector<int> data(a, a+n);
		sort(data.begin(), data.end());
		int left = 0, right = data.size()-1;

		while (left < right) {
			int sum = data[left] + data[right];
			if (sum == target) {
				cout << setw(2) << data[left] << " " << setw(2) << data[right] << endl;
				++left;
				--right;
			} else if (sum < target) {
				++left;
			} else {
				--right;
			}
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