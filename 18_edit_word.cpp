#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<string> edit_one_word(string cur) {
	vector<string> res;

	for (int i = 0; i < cur.size(); ++i) {
		for (char c = 'a'; c <= 'z'; ++c) {
			if (cur[i] == c)
				continue;

			string tmp = cur;
			tmp[i] = c;
			res.push_back(tmp);
		}
	}

	return res;
}


int main() {
	set<string> dict;
	ifstream ifs("dict.txt");
	string line;
	while (getline(ifs, line)) 
		dict.insert(line);

	set<string> visited;
	queue<string> q;
	map<string, string> trace;

	string src = "damp";
	string dst = "like";
	q.push(src);
	visited.insert(src);

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		if (cur.compare(dst) == 0) {
			while (cur.compare(src) != 0) {
				cout << cur << " ";
				cur = trace[cur];
			}
			cout << src << endl;
			return 0;
		} 

		vector<string> tmp = edit_one_word(cur);
		for (int i = 0; i < tmp.size(); ++i) {
			if (visited.find(tmp[i]) == visited.end() && dict.find(tmp[i]) != dict.end()) {
				q.push(tmp[i]);
				visited.insert(tmp[i]);
				trace[tmp[i]] = cur;
			}
		}
	}

	return 0;
}
