#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	string count_characters(string s1) {
		if (s1.length() == 0) return NULL;
		string res = "";
		int count = 1;

		for (int i = 1; i < s1.length(); i++) {
			if (s1[i] != s1[i-1]) {
				res += s1[i-1];
				res += count+'0';
				count = 1;
			} else {
				count++;
			}
		}
		// Remember to process last element!!
		res += s1[s1.length()-1];
		res += count+'0';

		if (res.size() < s1.size()) {
			return res;
		} else {
			return s1;
		}
	}
};

int main()
{
	Solution sol;

	cout << sol.count_characters("aaaaaabbbcccccdddd") << endl;
	cout << sol.count_characters("abcdefghijkl") << endl;

	return 0;
}
