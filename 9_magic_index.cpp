#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int magic_index(vector<int> data) {
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == i) { return i; }
			else if (data[i] > i) { return -1; }
		}
		return -1;
	}

	// if distinct
	int magic_index1(vector<int> data) {
		int start = 0;
		int end = data.size()-1;

		while (start <= end && start >= 0 && end < data.size()) {
			int mid = (start+end)/2;
			if (data[mid] == mid) { 
				return mid; 
			} else if (data[mid] < mid) {
				// on right side;
				start = mid+1;
			} else {
				end = mid-1;
			}
		}

		return -1;
	}

	// if not distince
	int helper(vector<int> &data, int start, int end) {
		if (start > end || start < 0 || end >= data.size()) {
			return -1;
		}

		int mid = (start+end)/2;
		if (data[mid] == mid) { return mid; }

		/* go left */
		int left = helper(data, start, min(mid-1, data[mid]));
		if (left >= 0) { return left; }

		/* go right */
		int right = helper(data, max(mid+1, data[mid]), end);
		if (right >= 0) { return right; }

		return -1;
	}

	int magic_index2(vector<int> data) {
		return helper(data, 0, data.size()-1);
	}
};

int main()
{
	Solution sol;
	vector<int> data;

	for (int i = 0; i < 100; i++) {
		data.push_back(i*3-150);

	}
	sort(data.begin(), data.end());

	cout << sol.magic_index(data) << endl;
	cout << sol.magic_index1(data) << endl;
	cout << sol.magic_index2(data) << endl;

	return 0;
}
