#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(const string &a, const string &b) {
	string c = a;
	string d = b;

	sort(c.begin(), c.end());
	sort(d.begin(), d.end()); 

	return c > d;
}

int main()
{
	// Solution sol;
	vector<string> a;

	a.push_back("nvk");
	a.push_back("abcde");
	a.push_back("asdf");
	a.push_back("bcdea");
	a.push_back("qwer");
	a.push_back("dceab");

	cout << "before: ";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;

	// sol.sort_string_by_anagram(a);
	sort(a.begin(), a.end(), compare);

	cout << "after: ";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
