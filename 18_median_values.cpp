#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	priority_queue<int> q_max;
	priority_queue<int, vector<int>, greater<int> > q_min;

	// ifstream ifs("dict.txt");
	// string line;

	// while (getline(ifs, line)) {
	// 	if (q_min.size() <= q_max.size()) {
	// 		q_min.push(line.size());
	// 	} else {
	// 		q_max.push(line.size());
	// 	}
	// }	

	int a[] = {1,2,3,4,5,6};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> data(a, a+n);

	for (int i = 0; i < data.size(); ++i) {
		if (q_min.size() <= q_max.size()) {
			q_min.push(data[i]);
		} else {
			q_max.push(data[i]);
		}		
	}

	if (q_min.size() == q_max.size()) {
		int v1 = q_min.top();
		int v2 = q_max.top();
		cout << (v1 + v2) / 2.0 << endl;	
	} else {
		cout << q_min.top() << endl;
	}

	return 0;
}