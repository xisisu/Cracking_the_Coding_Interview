#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define SIZE 92

class Solution { 
	int data[SIZE] = {0};
	int offset[3] = {-1, -1, -1};

public:
	int pop(int num) {
		if (num < 0 || num > 2 || offset[num] <= 0) { return -1; }

		int val = data[offset[num]+(SIZE/3)*num];
		--offset[num];

		cout << "pop " << val << " from " << num << endl;

		return val;
	}

	int push(int num, int val) {
		if (num < 0 || num > 2 || offset[num]+1 >= (SIZE/3)*(num+1)) { return -1; }

		++offset[num];
		data[offset[num]+(SIZE/3)*num] = val;

		cout << "push " << val << " to " << num << endl;

		return 0;
	}

	int top(int num) {
		if (num < 0 || num > 2 || offset[num] <= 0) { return -1; }

		return data[offset[num]+(SIZE/3)*num];	
	}

	void toString() {
		for (int i = 0; i < 3; i++) {
			cout << "Stack " << i << ": ";
			for (int j = 0; j <= offset[i]; j++) {
				cout << data[(SIZE/3)*i+j] << " ";
			}
			cout << "(" << offset[i]+1 << ")" << endl;
		}
	}

	void clear() {
		for (int i = 0; i < 3; i++)
			offset[i] = -1;
	}

	int pop1(int num) {
		if (num < 0 || num > 2 || offset[num] <= 0) { return -1; }

		int val = -1;
		if (num != 1) {
			val = data[offset[num]+(SIZE/3)*num];
		} else {
			val = data[(SIZE/3)*2-offset[num]-1];
		}
		--offset[num];

		cout << "pop " << val << " from " << num << endl;

		return val;
	}	

	int push1(int num, int val) {
		if (num < 0 || num > 2) { return -1; }
		if (num == 2 && offset[2]+1 >= (SIZE/3)*3) { return -1; }
		if (num !=2 && offset[0]+offset[1] >= (SIZE/3)*2) { return -1; }

		cout << "push " << val << " to " << num << endl;

		++offset[num];
		if (num != 1) {
			data[offset[num]+(SIZE/3)*num] = val;
		} else {
			data[(SIZE/3)*2-offset[num]-1] = val;
		}
		
		return 0;
	}

	int top1(int num) {
		if (num < 0 || num > 2 || offset[num] <= 0) { return -1; }

		int val = 0;
		if (num != 1) {
			val = data[offset[num]+(SIZE/3)*num];
		} else {
			val = data[(SIZE/3)*2-offset[num]-1];
		}

		return val;
	}

	void toString1() {
		for (int i = 0; i < 3; i++) {
			cout << "Stack " << i << ": ";
			for (int j = 0; j <= offset[i]; j++) {
				if (i != 1) {
					cout << data[(SIZE/3)*i+j] << " ";					
				} else {
					cout << data[(SIZE/3)*2-j-1] << " ";
				}
			}
			cout << "(" << offset[i]+1 << ")" << endl;
		}

		cout << "whole array: ";
		for (int i = 0; i < (SIZE/3)*3; i++) {
			if ( i % (SIZE/3) == 0) {
				cout << endl;
			}
			cout << data[i] << " ";
		}
	}
};

int main()
{
	Solution res;

    srand(time(NULL));

	for (int i = 0; i < SIZE/2; i++) {
		if (res.push(rand()%3, rand()%9+1) == -1) {
			cout << "failed" << endl;
			break;
		}
	}

	res.toString();

	cout << endl << "Now starting to pop" << endl;

	for (int i = 0; i < SIZE/4; i++) {
		if (res.pop(rand()%3) == -1) {
			cout << "failed" << endl;
			break;
		}
	}

	res.toString();

	return 0;
}
