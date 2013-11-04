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

		return res;
	}
};

int main()
{
	string s1 = "aaabbbcdefgasdff";

	Solution res;

	string s2 = res.count_characters(s1);

	cout << s2 << endl;

	return 0;
}
