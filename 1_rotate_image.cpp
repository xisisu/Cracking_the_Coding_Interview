#include <iostream>
using namespace std;

int main()
{
	int n = 5;
	int data[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			data[i][j] = i+1;
	}

	cout << "Before" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (int layer = 0; layer < n/2; layer++) {
		int first = layer;
		int last = n-1-layer;
		for (int i = first; i < last; i++) {
			int tmp = data[first][i];
			int offset = i-first;
			data[first][i] = data[last-offset][first];
			data[last-offset][first] = data[last][last-offset];
			data[last][last-offset] = data[i][last];
			data[i][last] = tmp;
		}
	}

	cout << "After" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}

	return 0;
}
