#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	void replace_space(char *str, int length) {
		int count = 0;

		for (int i = 0; i < length; i++) {
			if (*(str+i) == ' ') count++;
		}

		// Remember to add this to the end!!
		*(str+length+count*2-1) = '\0';

		int i = length-1;
		int j = length+count*2-1;
		while (j > i && i >= 0) {
			if (*(str+i) == ' ') {
				*(str+j) = '0'; j--;
				*(str+j) = '2'; j--;
				*(str+j) = '%'; j--;
			} else {
				*(str+j) = *(str+i); j--;
			}

			i--;
		}
	}

};

int main()
{
	char str[] = "Mr John Smith       ";

	Solution res;

	res.replace_space(str, 13);

	cout << str << endl;

	return 0;
}
