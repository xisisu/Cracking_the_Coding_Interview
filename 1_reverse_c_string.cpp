#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	void reverse_c_string(char *str) {
		char *end = str;
		char tmp;

		while (*end) { end++; }
		end--;

		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}

};

int main()
{
	char test1[] = "abcdefghijklmnopqrstuvwxyz";

	Solution res;
	res.reverse_c_string(test1);
	cout << test1 << endl;

	return 0;
}
