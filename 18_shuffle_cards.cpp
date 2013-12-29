#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Solution {
public:
	void shuffle_card(int a[], int n) {
		for (int i = n-1; i > 0; --i) {
			int seed = rand()%(i+1);
			int tmp = a[i];
			a[i] = a[seed];
			a[seed] = tmp;
		}

		return;
	}
};


int main() {
	Solution sol;
	int a[52];
	int n = 52;

	for (int i = 0; i < n; ++i)
		a[i] = i;

	sol.shuffle_card(a, n);

	for (int i = 0; i < n; ++i)
		cout << setw(2) << a[i] << " ";
	cout << endl;

	return 0;
}