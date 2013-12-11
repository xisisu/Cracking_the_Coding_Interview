#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int binary_search_with_empty_strings(vector<string> a, string x) {
		int left = 0, right = a.size()-1;

		while (left <= right) {
			while (a[left] == "") ++left;
			while (a[right] == "") --right;

			int mid = (left+right) / 2;
			while (a[mid] == "" && mid <= right) ++mid;
			if (mid > right) {
				mid = (left+right) / 2;
				while (a[mid] == "" && mid >= left) --mid;
				if (mid < left) return -1;
			}

			if (a[mid] == x) {
				return mid;
			} else if (a[mid] > x) {
				right = mid-1;
			} else {
				left = mid+1;
			}
		}

		return -1;
	}
};

int main()
{
	Solution sol;
	vector<string> a;

	a.push_back("at");
	a.push_back("");
	a.push_back("");
	a.push_back("");
	a.push_back("ball");
	a.push_back("");
	a.push_back("");
	a.push_back("car");
	a.push_back("");
	a.push_back("");
	a.push_back("dad");
	a.push_back("");
	a.push_back("");

	cout << "before: ";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;

	cout << sol.binary_search_with_empty_strings(a, "ball") << endl;
	
	return 0;
}
