#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution{
public:
	void swap(int &a, int &b) {
		a = a-b;
		b = a+b;
		a = b-a;
	}

	void swap1(int &a, int &b) {
		a = a^b;
		b = a^b;
		a = a^b;
	}
};

int main() {
	Solution sol;
	srand(time(NULL));
	int a = rand()%100;
	int b = rand()%100;

	cout << a << " " << b << endl;
	sol.swap(a, b);
	cout << a << " " << b << endl;
	sol.swap1(a, b);
	cout << a << " " << b << endl;

	return 0;
}