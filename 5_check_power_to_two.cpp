#include <iostream>
using namespace std;

class Solution {
public:
	bool check_power_to_two(int n) {
		return ((n & (n-1)) == 0);
	}
};

int main()
{
	Solution sol;

	for (int i = 1; i <= 16; i++) {
		cout << i << ": ";
		cout << sol.check_power_to_two(i) << endl;
	}

	return 0;
}
