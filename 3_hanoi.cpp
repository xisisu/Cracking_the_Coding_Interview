#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	void hanoi(vector<int> &src, vector<int> &buf, vector<int> &dst, int n) {
		if (n == 1) {
			dst.push_back(src.back());
			src.pop_back();
			return; 
		}

		hanoi(src, dst, buf, n-1);
		
		dst.push_back(src.back());
		src.pop_back();	
	
		hanoi(buf, src, dst, n-1);

		return;
	}
};

int main()
{
	Solution res;
	vector<int> src;
	vector<int> buf;
	vector<int> dst;

	for (int i = 10; i > 0; --i) {
		src.push_back(i);
	}

	cout << "before" << endl;
	cout << "src: ";
	for (int i = 0; i < src.size(); ++i) {
		cout << src[i] << " ";
	}
	cout << endl;

	cout << "buf: ";
	for (int i = 0; i < buf.size(); ++i) {
		cout << buf[i] << " ";
	}
	cout << endl;

	cout << "dst: ";
	for (int i = 0; i < dst.size(); ++i) {
		cout << dst[i] << " ";
	}
	cout << endl;

	res.hanoi(src, buf, dst, 10);

	cout << endl << "after" << endl;
	cout << "src: ";
	for (int i = 0; i < src.size(); ++i) {
		cout << src[i] << " ";
	}
	cout << endl;

	cout << "buf: ";
	for (int i = 0; i < buf.size(); ++i) {
		cout << buf[i] << " ";
	}
	cout << endl;

	cout << "dst: ";
	for (int i = 0; i < dst.size(); ++i) {
		cout << dst[i] << " ";
	}
	cout << endl;

	return 0;
}
