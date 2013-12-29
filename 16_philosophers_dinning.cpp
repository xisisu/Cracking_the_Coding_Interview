#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>

using namespace std;

#define NUM 5

mutex mtx[NUM];

void take_fork(int i) {
	while(!mtx[i].try_lock()) {
		sleep(rand()%2);
		cout << "sleep for lock " << i << endl;
	}
}

void put_fork(int i) {
	mtx[i].unlock();
}

void philosopher (int i) {
	int j = (i+1)%NUM;

	while (true) {
		// prioritize resource to avoid deadlock
		if (i == NUM-1) {
			take_fork(j);
			cout << "person " << i << " grab fork " << j << endl;
			take_fork(i);
			cout << "person " << i << " grab fork " << i << endl;
		} else {
			take_fork(i);
			cout << "person " << i << " grab fork " << i << endl;
			take_fork(j);
			cout << "person " << i << " grab fork " << j << endl;
		}

		put_fork(i);
		cout << "person " << i << " put fork " << i << endl;
		put_fork(j);
		cout << "person " << i << " put fork " << j << endl;	
	}
}

int main() {
	thread t[NUM];

	for (int i = 0; i < NUM; ++i)
		t[i] = thread(philosopher, i);

	for (int i = 0; i < NUM; ++i)
		t[i].join();

	return 0;
}