#include <iostream>
using namespace std;

int main()
{
	int M = 8;
	int N = 9;
	int data[M][N];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			data[i][j] = i+1;
	}

	data[3][4] = 0;
	data[5][6] = 0;

	cout << "Before" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int col, row;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (data[i][j] == 0) {
				row = i;
				col = j;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++)
		data[i][col] = 0;
	for (int j = 0; j < N; j++)
		data[row][j] = 0;

	for (int i = 0; i < M; i++) {
		if (i == row) continue;

		for (int j = 0; j < N; j++) {
			if (j == col) continue;

			if (data[i][j] == 0) {
				data[row][j] = 1;
				data[i][col] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (i == row) continue;
		for (int j = 0; j < N; j++) {
			if (j == col) continue;
			if (data[row][j] == 1 || data[i][col] == 1) 
				data[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++)
		data[i][col] = 0;
	for (int j = 0; j < N; j++)
		data[row][j] = 0;

	cout << "After" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}

	return 0;
}
