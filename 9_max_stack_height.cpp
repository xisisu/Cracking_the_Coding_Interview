#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
	int h, w, d;
};

int compare(const void *a, const void *b) {
	 return (*(Box *)a).h < (*(Box *)b).h;
}

class Solution {
public:
	int max_stack_height(Box data[], int n) {
		qsort(data, n, sizeof(data[0]), compare);
		
		cout << "input data:" << endl;
		for (int i = 0; i < n; ++i) {
			cout << "(" << data[i].h << " " << data[i].w << " " << data[i].d << ")" << " ";
		}
		cout << endl;

		// msh: maximum possible stack height with box i on top
		int msh[n];
		for (int i = 0; i < n; ++i) {
			msh[i] = data[i].h;
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (data[i].w < data[j].w && 
					data[i].d < data[j].d && 
					msh[i] < msh[j] + data[i].h) {
					msh[i] = msh[j] + data[i].h;
				}
			}
		}

		int max = -1;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (max < msh[i]) {
				max = msh[i];
				idx = i;
			}
		}

		cout << "Using: " << endl;
		cout << "(" << data[idx].h << " " << data[idx].w << " " << data[idx].d << ")" << " ";
		for (int i = idx-1; i >= 0; --i) {
			if (msh[i] == msh[idx]-data[idx].h) {
				cout << "(" << data[i].h << " " << data[i].w << " " << data[i].d << ")" << " ";
				idx = i;
			}
		}
		cout << endl;

		return max;
	}

};

int main()
{
	Solution sol;
	Box data[] = { {1,1,1}, {3,3,3}, {2,2,2}, {5,4,3}, {4,3,2}, {1,7,6}, {10,12,32} };
	int n = sizeof(data) / sizeof(data[0]);

	cout << sol.max_stack_height(data, n) << endl;

	return 0;
}
