#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// http://people.csail.mit.edu/bdean/6.046/dp/dp_9.swf

class Solution {
public:
	int bool_expression(string input, bool target, int start, int end) {
		if (start == end) {
			if ( (input[start] == '1' && target) ||
				 (input[start] == '0' && !target) ) {
				return 1;
			} else {
				return 0;
			}
		}

		int count = 0;
		if (target) {
			for (int i = start + 1; i <= end; i += 2) {
				switch (input[i]) {
				case '&':
					count += bool_expression(input, true, start, i-1) * bool_expression(input, true, i+1, end);
					break;
				case '|':
					count += bool_expression(input, true, start, i-1) * bool_expression(input, true, i+1, end);
					count += bool_expression(input, false, start, i-1) * bool_expression(input, true, i+1, end);
					count += bool_expression(input, true, start, i-1) * bool_expression(input, false, i+1, end);
					break;
				case '^':
					count += bool_expression(input, true, start, i-1) * bool_expression(input, false, i+1, end);
					count += bool_expression(input, false, start, i-1) * bool_expression(input, true, i+1, end);
					break;
				default:
					break;
				}
			}
		} else {
			for (int i = start + 1; i <= end; i += 2) {
				switch (input[i]) {
				case '|':
					count += bool_expression(input, false, start, i-1) * bool_expression(input, false, i+1, end);
					break;
				case '&':
					count += bool_expression(input, false, start, i-1) * bool_expression(input, false, i+1, end);
					count += bool_expression(input, false, start, i-1) * bool_expression(input, true, i+1, end);
					count += bool_expression(input, true, start, i-1) * bool_expression(input, false, i+1, end);
					break;
				case '^':
					count += bool_expression(input, true, start, i-1) * bool_expression(input, true, i+1, end);
					count += bool_expression(input, false, start, i-1) * bool_expression(input, false, i+1, end);
					break;
				default:
					break;
				}
			}
		}

		return count;
	}

	int bool_expression(string input, bool target) {
		return bool_expression(input, target, 0, input.size()-1);
	}

	// dp approach in http://people.csail.mit.edu/bdean/6.046/dp/dp_9.swf
	int bool_expression1(string input, bool target) {
		int n = input.length()/2 + 1;
		int T_val[n][n];
		int F_val[n][n];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				T_val[i][j] = 0;
				F_val[i][j] = 0;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (input[2*i] == '1') { T_val[i][i] = 1; }
			else { F_val[i][i] = 1; }
		}

		for (int len = 1; len < n; ++len) {
			for (int i = 0; i+len < n; ++i) {
				// divided into two parts, [i][j] and [j+1][i+len]
				for (int j = i; j < i+len && j < n; ++j) {
					switch (input[2*j+1]) {
					case '&':
						T_val[i][i+len] += T_val[i][j] * T_val[j+1][i+len];

						F_val[i][i+len] += F_val[i][j] * F_val[j+1][i+len];
						F_val[i][i+len] += T_val[i][j] * F_val[j+1][i+len];
						F_val[i][i+len] += F_val[i][j] * T_val[j+1][i+len];
						break;
					case '|':
						T_val[i][i+len] += T_val[i][j] * T_val[j+1][i+len];
						T_val[i][i+len] += T_val[i][j] * F_val[j+1][i+len];
						T_val[i][i+len] += F_val[i][j] * T_val[j+1][i+len];

						F_val[i][i+len] += F_val[i][j] * F_val[j+1][i+len];
						break;
					case '^':
						T_val[i][i+len] += T_val[i][j] * F_val[j+1][i+len];
						T_val[i][i+len] += F_val[i][j] * T_val[j+1][i+len];

						F_val[i][i+len] += T_val[i][j] * T_val[j+1][i+len];
						F_val[i][i+len] += F_val[i][j] * F_val[j+1][i+len];
						break;
					default :
						cout << "invalid input" << endl; 
						return 0;
					}
				}
			}
		}

		cout << "True Table: " << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << setw(7) << T_val[i][j] << " ";
			cout << endl;
		}

		cout << "False Table: " << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << setw(7) << F_val[i][j] << " ";
			cout << endl;
		}

		if (target) { return T_val[0][n-1]; }
		else { return F_val[0][n-1]; }
	}
};

int main()
{
	Solution sol;

	cout << sol.bool_expression1("1^0|0|1", true) << endl;

	return 0;
}
