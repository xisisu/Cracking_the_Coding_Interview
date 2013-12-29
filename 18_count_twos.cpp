#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	int helper(int n) {
		int res = 0;
		while (n > 0) {
			if (n%10 == 2) {
				++res;
			}
			n /= 10;
		}
		return res;
	}

	int count_twos1(int n) {
		int res = 0;
		for (int i = 2; i <= n; ++i) {
			res += helper(i);
		}

		return res;
	}

	int count_twos(int n) {
		stringstream ss;
		ss << n;
		string num = ss.str();
		int sum = 0;
		int sum2 = 0;
		int base = 1;
		int pre = 0;


		for (int i = 0; i < num.size(); ++i) {
			if (i != 0) {
				pre *= 10;
				pre += num[i-1]-'0';
			}

			// cout << "doing: " << num[i] << ", sum: " << sum << ", sum2: " << sum2 << endl;

			sum += pre;
			if (num[i] > '2')
				++sum;
			
			if (num[i] == '2') {
				if (i == num.size()-1) {
					++sum2;
				} else {
					string sub = num.substr(i+1, num.size()-(i+1));
					// cout << "    remain: " << sub << endl;
					++sum2;
					stringstream temp;
					temp << sub;
					int remain;
					temp >> remain;
					sum2 += remain;
				}
			}

			base *= 10;
			sum *= 10;
		}

		sum /= 10;

		return sum + sum2;
	}
};

int main() {
	Solution sol;

	cout << sol.count_twos(23612) << endl << endl;
	cout << sol.count_twos1(23612) << endl;

	return 0;
}