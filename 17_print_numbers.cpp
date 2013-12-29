#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string digits[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	string teens[10] = { "", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	string tens[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Swventy", "Eighty", "Ninety" };
	string bigs[6] = { "", "Thousand", "Million", "Billion", "Trillion", "Quadrillion" };

	string print_numbers(long long n) {
		if (n == 0)
			return "Zero";
		else if ( n < 0)
			return "Negative " + print_numbers(-1 * n);

		int count = 0;
		string res = "";

		while (n > 0) {
			if (n % 1000 != 0) {
				res = under_100(n % 1000) + bigs[count] + " " + res;
			}
			n /= 1000;
			++count;
		}

		return res;
	}

	string under_100(int n) {
		string res = "";

		if (n >= 100) {
			res += digits[n/100] + "Hundred ";
			n %= 100;
		}

		if (n >= 11 && n <= 19) 
			return res += teens[n-10] + " ";
		else if (n == 10 || n >= 20) {
			res += tens[n/10] + " ";
			n %= 10;
		}

		if (n >= 1 && n <= 9) 
			res += digits[n] + " ";

		return res;
	}
};

int main() {
	Solution sol;

	for (int i = 0; i < 9000; i += 101) {
		cout << i << " " << sol.print_numbers(i) << endl;
	}

	return 0;
}
