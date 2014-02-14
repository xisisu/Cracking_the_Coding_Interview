#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int comp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}

int main() {
	ifstream ifs("17_word_frequency.txt");
	string line;

	map<string, int> m;

	while (getline(ifs, line)) {
		stringstream stream(line);
		string word;

		while (stream >> word) {
			++m[word];
		}
	}

	vector<pair<string, int> > table;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) 
		table.push_back(pair<string, int>(it->first, it->second));

	sort(table.begin(), table.end(), comp);

	for (int i = 0; i < table.size(); ++i)
		cout << table[i].first << " " << table[i].second << endl;

	return 0;
}