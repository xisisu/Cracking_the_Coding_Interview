#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	bool rotate_string(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		if (s1.length() < 2) return true;

		string s3 = s1+s1;

		if (s3.find(s2) != -1) {
			return true;
		} else {
			return false;
		}
	}

};

int main()
{
	string s1 = "abcdefghijklmnopqrstuvwxyz";
	string s2 = "nopqrstuvwxyzabcdefghijklm";

	Solution res;
	cout << res.rotate_string(s1, s2) << endl;

	return 0;
}
