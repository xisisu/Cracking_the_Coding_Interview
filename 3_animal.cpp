#include <iostream>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
	queue<int> dog;
	queue<int> cat;

public:
	void enqueue(int val) {
		if (rand()%2 == 0) {
			dog.push(val);
		} else {
			cat.push(val);
		}
	}

	int dequeueAny() {
		int val; 

		if (dog.front() > cat.front()) {
			val = cat.front();
			cat.pop();
		} else {
			val = dog.front();
			dog.pop();
		}

		return val;
	}

	int dequeueDog() {
		if (dog.empty()) { return -1; }

		int val = dog.front();
		dog.pop();

		return val;
	}

	int dequeueCat() {
		if (cat.empty()) { return -1; }

		int val = cat.front();
		cat.pop();

		return val;
	}

	void toString() {
		queue<int> tmp_cat = cat;
		queue<int> tmp_dog = dog;

		cout << "dog: ";
		while (!tmp_dog.empty()) {
			cout << tmp_dog.front() << " ";
			tmp_dog.pop();
		}
		cout << endl;

		cout << "cat: ";
		while (!tmp_cat.empty()) {
			cout << tmp_cat.front() << " ";
			tmp_cat.pop();
		}
		cout << endl;
	}
};

int main()
{
	Solution res;
	srand(time(NULL));

	for (int i = 0; i < 20; ++i) {
		res.enqueue(i);
	}
	cout << "before: " << endl;
	res.toString();

	cout << endl << "dequeue Any: " << endl;
	for (int i = 0; i < 10; ++i) {
		cout << res.dequeueAny() << " ";
	}
	cout << endl;
	res.toString();

	cout << endl << "dequeue Dog: " << endl;
	for (int i = 0; i < 10; ++i) {
		cout << res.dequeueDog() << " ";
	}
	cout << endl;
	res.toString();

	cout << endl << "dequeue Cat: " << endl;
	for (int i = 0; i < 10; ++i) {
		cout << res.dequeueCat() << " ";
	}
	cout << endl;
	res.toString();

	return 0;
}
