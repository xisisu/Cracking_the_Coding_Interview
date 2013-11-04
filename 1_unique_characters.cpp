#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	// input is limited to 256!
	bool unique_characters_book_1(string input) {
		if (input.length() < 2) return true;
		if (input.length() > 256) return false;

		bool charset[256] = {false};

		for (int i = 0; i < input.length(); i++) {
			int val = input[i];
			if (charset[val] == true) {
				return false;
			}
			charset[val] = true;
		}

		return true;
	}

	// if only 'a' to 'z', can use one int
	bool unique_characters_book_2(string input) {
		if (input.length() < 2) return true;
		if (input.length() > 256) return false;

		int checker = 0;
		
		for (int i = 0; i < input.length(); i++) {
			int val = input[i]-'a';
			if ((checker & (1 << val)) > 0) {
				return false;
			}
			checker |= (1 << val);
		}

		return true;
	}

	bool unique_characters_1(string input) {
		if (input.length() < 2) return true;
		if (input.length() > 256) return false;

		for (int i = 0; i < input.length()-1; i++) {
			for (int j = i+1; j < input.length(); j++) {
				if (input[i] == input[j]) {
					return false;
				}
			}
		}

		return true;
	}

	bool unique_characters(string input) {
		if (input.length() < 2) return true;
		if (input.length() > 256) return false;

		set<char> table;

		for (int i = 0; i < input.length(); i++) {
			if (table.find(input[i]) == table.end()) {
				table.insert(input[i]);
			} else {
				return false;
			}
		}

		return true;
	}
};

int main()
{
	string test1 = "abcdefghijklmnopqrstuvwxyz";
	string test2 = "abcdefghiiklmnopqrstuvwxyz";

	Solution res;

	cout << res.unique_characters(test1) << endl;
	cout << res.unique_characters(test2) << endl;

	cout << res.unique_characters_1(test1) << endl;
	cout << res.unique_characters_1(test2) << endl;

	cout << res.unique_characters_book_1(test1) << endl;
	cout << res.unique_characters_book_1(test2) << endl;

	cout << res.unique_characters_book_2(test1) << endl;
	cout << res.unique_characters_book_2(test2) << endl;

	return 0;
}
