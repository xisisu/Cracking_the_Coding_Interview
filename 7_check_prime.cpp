#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int>	prime;

public:
	// naive implementation
	bool check_prime(int num) {
		if (num < 2) { return false; }

		for (int i = 2; i < num; ++i) {
			if ( (num % i) == 0 ) { return false; }
		}

		return true;
	}

	// a little better impl
	bool check_prime1(int num) {
		if (num < 2) { return false; }

		int limit = sqrt(num);
		for (int i = 0; i <= limit; ++i) {
			if ( (num % i) == 0) { return false; }
		}

		return true;
	}

	// maintain an array of prime numbers
	bool check_prime2(int num) {
		if (num < 2) { return false; }

		int i = prime.size() > 0 ? prime.back()+1 : 2;

		while (i <= num) {
			int j = 0;
			while (j < prime.size()) {
				if (i % prime[j] == 0) { break; }
				++j;
			}
			if (j == prime.size()) {
				prime.push_back(i);
			}
			++i;
		}

		for (int k = 0; k < prime.size(); k++) {
			if (num == prime[k]) 
				return true; 
			if (num % prime[k] == 0) 
				return false;
		}
	}
};

int main()
{
	Solution sol;

	for (int i = 0; i < 500; i++) {
		if (sol.check_prime2(i)) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
