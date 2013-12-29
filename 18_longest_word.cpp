#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int compare(string a, string b) {
	return a.length() > b.length();
}

bool can_build(set<string> &table, string str, bool original) {
	if (table.find(str) != table.end() && !original) {
		return true;
	}

	for (int i = 1; i < str.length(); ++i) {
		string left = str.substr(0, i);
		string right = str.substr(i);

		if (table.find(left) != table.end() && 
			can_build(table, right, false)) 
			return true;			
	}

	return false;
}


int main() {
	vector<string> data;
	set<string> table;
	ifstream ifs("dict.txt");
	string line;

	while (getline(ifs, line)) {
		data.push_back(line);
		table.insert(line);
	}

	sort(data.begin(), data.end(), compare);

	for (int i = 0; i < data.size(); ++i) {
		if (can_build(table, data[i], true)) {
			cout << i << " " << data[i] << endl;
			break;
		}
	}

	return 0;
}