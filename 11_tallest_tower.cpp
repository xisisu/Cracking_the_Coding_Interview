#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
	int h, w;
};

void sort(Person a[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-i-1; ++j) {
			if (a[j].h < a[j+1].h) {
				Person tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	return;
}

class Solution {
public:
	int tallest_tower(Person a[], int n) {
		sort(a, n);

		cout << "input: ";
		for (int i = 0; i < n; ++i)
			cout << "(" << a[i].h << ", " << a[i].w << ") ";
		cout << endl;

		int dp[n];
		for (int i = 0; i < n; ++i) {
			dp[i] = a[i].h;
		}

		int res = dp[0];
		int res_idx = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (a[i].h < a[j].h &&
					a[i].w < a[j].w &&
					dp[i] < dp[j] + a[i].h) {
					dp[i] = dp[j] + a[i].h;
				}
			}
			if (dp[i] > res) {
				res = dp[i];
				res_idx = i;
			}
		}
		
		cout << "use: ";
		cout << "(" << a[res_idx].h << ", " << a[res_idx].w << ") ";
		for (int i = res_idx-1; i >= 0; --i) {
			if (dp[i] == dp[res_idx] - a[res_idx].h) {
				cout << "(" << a[i].h << ", " << a[i].w << ") ";
				res_idx = i;
			}
		}
		cout << endl;
		cout << "max height: " << res << endl;

		return res;
	}
};

int main()
{
	Solution sol;
	Person a[] = { {65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110} };
	int n = sizeof(a) / sizeof(a[0]);

	sol.tallest_tower(a, n);
	
	return 0;
}
