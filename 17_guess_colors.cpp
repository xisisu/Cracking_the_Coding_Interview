#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>;
using namespace std;

class Solution{
public:
	int guess_colors(string sol, string guess) {
		if (sol.size() != guess.size() || sol.size() == 0) 
			return 0;
		
		int hit = 0;
		int fake_hit = 0;
		map<char, int> m;

		for (int i = 0; i < sol.size(); ++i) {
			if (sol[i] == guess[i]) 
				++hit;
			else 
				++m[sol[i]];
		}

		for (int i = 0; i < guess.size(); ++i) 
			if (m.find(guess[i]) != m.end()) {
				--m[guess[i]];
				if (m[guess[i]] == 0) {
					m.erase(guess[i]);
				}
				++fake_hit;
			}

		return hit * 10 + fake_hit;
	}
};

int main() {
	Solution sol;

	cout << sol.guess_colors("RGBY", "GGRR");

	return 0;
}
