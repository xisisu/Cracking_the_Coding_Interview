#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	// or sort the string and then compare
	// bool string_permutation_1(string s1, string s2) {
	// 	if (s1.length() != s2.length()) return false;
	// 	if (s1.length() == 0) return true;

	// 	string s3 = sort(s1.begin(), s1.end());
	// 	string s4 = sort(s2.begin(), s2.end());

	// 	return (s3.compare(s4) == 0);
	// }

	bool string_permutation(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		if (s1.length() == 0) return true;

		int table[256] = {0};

		for (int i = 0; i < s1.length(); i++) {
			table[s1[i]]++;
			table[s2[i]]--;
		}

		for (int i = 0; i < 256; i++) {
			if (table[i] != 0) {
				return false;
			}
		}

		return true;
	}

};

int main()
{
	string s1 = "abcdefghijklmnopqrstuvwxyz";
	string s2 = "qrstuabcdefghijklmnopvwxyz";

	Solution res;
	cout << res.string_permutation(s1, s2) << endl;

	return 0;
}
