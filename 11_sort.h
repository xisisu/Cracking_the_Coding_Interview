#include <iostream>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iomanip>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

void bubble_sort(int a[], int n) {
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n-i-1; ++j) 
			if (a[j] > a[j+1]) 
				swap(a[j], a[j+1]);
		
	return;
}

void selection_sort(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		int max = INT_MIN;
		int max_idx;
		for (int j = 0; j < n-i; ++j) {
			if (a[j] > max) {
				max = a[j];
				max_idx = j;
			}
		}
		swap(a[n-1-i], a[max_idx]);
	}

	return;
}	

void __merge(int a[], int helper[], int low, int mid, int high) {
	for (int i = low; i <= high; ++i)
		helper[i] = a[i];

	int left = low;
	int right = mid+1;
	int cur = low;

	while (left <= mid && right <= high) {
		if (helper[left] <= helper[right])
			a[cur++] = helper[left++];
		else 
			a[cur++] = helper[right++];
	}

	int remain = mid - left;
	for (int i = 0; i <= remain; ++i)
		a[cur+i] = helper[left+i];
	// no need to copy right part, it is already sorted.
}

void __merge_sort(int a[], int helper[], int low, int high) {
	if (low >= high) return;

	int mid = (low + high) / 2;
	__merge_sort(a, helper, low, mid);
	__merge_sort(a, helper, mid+1, high);
	__merge(a, helper, low, mid, high);
}

void merge_sort(int a[], int n) {
	int helper[n];
	__merge_sort(a, helper, 0, n-1);		
}

void __quick_sort(int a[], int left, int right) {
	int i = left, j = right;
	int pivot = a[(left+right) / 2];

	while (i <= j) {
		while (a[i] < pivot) ++i;
		while (a[j] > pivot) --j;

		if (i <= j)
			swap(a[i++], a[j--]);
	}

	if (left < j)
		__quick_sort(a, left, j);
	if (i < right)
		__quick_sort(a, i, right);
}

void quick_sort(int a[], int n) {
	__quick_sort(a, 0, n-1);
}

int binary_search(int a[], int n, int target) {
	int low = 0, high = n-1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == target) {
			return mid;
		} else if (a[mid] > target) {
			high = mid - 1;
		} else if (a[mid] < target) {
			low = mid+1;
		}
	}

	return -1;
}