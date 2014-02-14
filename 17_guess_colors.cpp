#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

class Solution{
public:
	int guess_colors(string sol, string guess) {
		if (sol.size() != guess.size() || sol.size() == 0) 
			return 0;
		
		int hit = 0;
		int fake_hit = 0;
		map<char, int> m;
		vector<int> mismatch;


		for (int i = 0; i < sol.size(); ++i) {
			if (sol[i] == guess[i]) 
				++hit;
			else {
				++m[sol[i]];
				mismatch.push_back(i);
			}
		}

		for (int i = 0; i < mismatch.size(); ++i) 
			if (m.find(guess[mismatch[i]]) != m.end()) {
				--m[guess[mismatch[i]]];
				if (m[guess[mismatch[i]]] == 0) {
					m.erase(guess[mismatch[i]]);
				}
				++fake_hit;
			}

		return hit * 10 + fake_hit;
	}
};

int main() {
	Solution sol;

	cout << sol.guess_colors("GGRR", "RGBY");

	return 0;
}
