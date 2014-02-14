#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void * aligned_malloc(size_t required_bytes, size_t alignment) {
	int offset = alignment - 1;
	void * p = (void *) malloc(required_bytes + offset);
	void * q = (void *) (((size_t)(p) + offset) & ~(alignment - 1));

	return q;
}

void * aligned_malloc1(size_t required_bytes, size_t alignment) {
	int offset = alignment - 1 + sizeof(void *);
	void * p1;
	void ** p2;

	if ( (p1 = (void *) malloc(required_bytes + offset)) == NULL )
		return NULL;

	p2 = (void **) (((size_t)(p1) + offset) & ~(alignment - 1));
	p2[-1] = p1;
	return p2;
}

void aligned_free(void *p2) {
	void * p1 = ((void **)p2)[-1];
	free(p1);
}


int main() {
	int alignment = 2048;
	int required_bytes = 10;

	// cout << sizeof(size_t) << endl;   // print 8
	void * p = (void *) malloc(required_bytes * sizeof(int));
	void * q = aligned_malloc(required_bytes, alignment);
	void * k = aligned_malloc1(required_bytes, alignment);

	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "k: " << k << endl;

	// aligned_free(p);
	// aligned_free(q);
	aligned_free(k);

	return 0;
}
