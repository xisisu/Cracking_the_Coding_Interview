#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

bool check(vector<vector<string> > &data, vector<string> &matrix) {
	int width = matrix[0].size();
	int height = matrix.size();

	// cout << "check: ";
	// for (int i = 0; i < matrix.size(); ++i)
	// 	cout << matrix[i] << " ";
	// cout << endl;

	for (int i = 0; i < width; ++i) {
		string res = "";
		for (int j = 0; j < height; ++j)
			res += matrix[j][i];

		if ( find(data[height].begin(), data[height].end(), res) == data[height].end() ) {
			// cout << "did not find " << res << endl;
			return false;
		}
	}

	return true;
}

void build_helper(vector<vector<string> > &data, int width, int height, vector<string> &res, int cur, set<string> &visited) {
	if (cur == height) {
		if (check(data, res)) {
			cout << "Find!" << endl;
			for (int i = 0; i < res.size(); ++i) {
				cout << res[i] << endl;
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < data[width].size(); ++i) {
		if (visited.find(data[width][i]) == visited.end()) {
			visited.insert(data[width][i]);
			res[cur] = data[width][i];
			build_helper(data, width, height, res, cur+1, visited);
			visited.erase(data[width][i]);
		}
	}

	return;
}

void build(vector<vector<string> > &data, int width, int height) {
	vector<string> res;
	set<string> visited;

	if (data[width].size() < height) {
		return;
	}

	string tmp;
	for (int i = 0; i < height; ++i)
		res.push_back(tmp);

	cout << "Building submatrix with width " << width << " and height " << height << endl;

	build_helper(data, width, height, res, 0, visited);

	return;
}



int main() {
	vector<vector<string> > data;
	ifstream ifs("dict.txt");
	string line;

	while (getline(ifs, line)) {
		while (data.size() <= line.size()) {
			vector<string> tmp;
			data.push_back(tmp);
		}
		data[line.size()].push_back(line);
	}

	int max_len = data.size()-1;
	int max_area = max_len * max_len;

	for (int i = max_area; i >= 1; --i) {
		for (int j = max_len; j >= 1; --j) {
			if (i % j == 0) {
				int k = i / j;
				if (k <= max_len) {			
					build(data, j, k);
				}
			}
		}
	}

	return 0;
}