#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main() {
	ifstream ifs("17_word_frequency.txt");
	string line;

	map<string, int> m;
	map<int, string> reverse_m;

	while (getline(ifs, line)) {
		stringstream stream(line);
		string word;

		while (stream >> word) {
			++m[word];
		}
	}

	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) 
		reverse_m[it->second] = it->first;

	map<int, string>::iterator reverse_it;
	for (reverse_it = reverse_m.begin(); reverse_it != reverse_m.end(); ++reverse_it)
		cout << reverse_it->second << " " << reverse_it->first << endl;

	return 0;
}