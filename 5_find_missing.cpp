#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int find_missing(vector<int> data, int col) {
		if (data.size() == 0) { return 0; }

		vector<int> onebits;
		vector<int> zerobits;

		for (int i = 0; i < data.size(); ++i) {
			if (data[i] & (1 << col)) {
				onebits.push_back(data[i]);
			} else {
				zerobits.push_back(data[i]);
			}
		}

		if (zerobits.size() <= onebits.size()) {
			int v = find_missing(zerobits, col+1);
			return (v << 1) | 0;
		} else {
			int v = find_missing(onebits, col+1);
			return (v << 1) | 1;
		}
	}

	int find_missing(vector<int> data) {
		return find_missing(data, 0);
	}
};

int main()
{
	Solution sol;
	vector<int> data;

	for (int i = 0; i < 32; i++) {
		if (i == 5) { continue; }
		data.push_back(i);
	}

	cout << sol.find_missing(data) << endl;

	return 0;
}
