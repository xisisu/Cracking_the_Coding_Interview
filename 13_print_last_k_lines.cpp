#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define NAME_SIZE 50

class Solution {
public:
	void print_last_k_lines(char* input, int k) {
		ifstream ifs(input);
		string line;
		queue<string> q;

		while (getline(ifs, line)) {
			if (q.size() > k)
				q.pop();
			q.push(line);
		}

		while (!q.empty()) {
			cout << q.front() << endl;
			q.pop();
		}
	}

	void print_last_k_lines1(char *input, int k) {
		ifstream ifs(input);
		string line;
		vector<string> L(k);

		int idx = 0;
		while (getline(ifs, line)) {
			L[idx%k] = line;
			idx++;
		}

		int start = idx > k ? (idx % k) : 0;
		int count = min(k, idx);

		for (int i = 0; i < count; ++i) {
			cout << L[(start+i)%k] << endl;
		}
	}
};

int main(int argc, char * argv[])
{
	Solution sol;

	sol.print_last_k_lines1("13_input.txt", 5);

	return 0;
}
