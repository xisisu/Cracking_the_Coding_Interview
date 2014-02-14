#include <iostream>
#include <stack>
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

// have question about this, don't know how it works
enum Tower { Zero, Left, Mid, Right };
class HanoiObj {
public:
	Tower src, buf, dst;
	int num, index;
	
	HanoiObj(Tower s, Tower b, Tower d, int n) : src(s), buf(b), dst(d), num(n) {
		if (n == 1) index = 1;
	}
	HanoiObj(Tower s, Tower d, int i) : src(s), dst(d), index(i) {
		num = 1; buf = Zero;
	}
	HanoiObj() {}

	void move(Tower src, Tower dst, int index) {
		cout << "Move Disk #" << index << " from Tower " << src << " to Tower " << dst << endl;
	}

	void TOH(int N, stack<HanoiObj *> &Hstack) {
		Tower s, b, d;
		int n;

		Hstack.push(new HanoiObj(Left, Mid, Right, N));

		while (!Hstack.empty()) {
			HanoiObj * tmp = Hstack.top(); Hstack.pop();

			s = tmp->src; b = tmp->buf; d = tmp->dst; n = tmp->num;

			if (n < 1) {
				continue;
			} else if (n == 1) {
				move(s, d, tmp->index);
			} else {
				Hstack.push(new HanoiObj(b, s, d, n-1));
				Hstack.push(new HanoiObj(s, d, n));
				Hstack.push(new HanoiObj(s, d, b, n-1));
			}

			delete tmp;
		}
	}
};


int main()
{
	HanoiObj * hanoi = new HanoiObj;
	stack<HanoiObj *> s;
	hanoi->TOH(3, s);



	// Solution res;
	// vector<int> src;
	// vector<int> buf;
	// vector<int> dst;

	// for (int i = 10; i > 0; --i) {
	// 	src.push_back(i);
	// }

	// cout << "before" << endl;
	// cout << "src: ";
	// for (int i = 0; i < src.size(); ++i) {
	// 	cout << src[i] << " ";
	// }
	// cout << endl;

	// cout << "buf: ";
	// for (int i = 0; i < buf.size(); ++i) {
	// 	cout << buf[i] << " ";
	// }
	// cout << endl;

	// cout << "dst: ";
	// for (int i = 0; i < dst.size(); ++i) {
	// 	cout << dst[i] << " ";
	// }
	// cout << endl;

	// res.hanoi(src, buf, dst, 10);

	// cout << endl << "after" << endl;
	// cout << "src: ";
	// for (int i = 0; i < src.size(); ++i) {
	// 	cout << src[i] << " ";
	// }
	// cout << endl;

	// cout << "buf: ";
	// for (int i = 0; i < buf.size(); ++i) {
	// 	cout << buf[i] << " ";
	// }
	// cout << endl;

	// cout << "dst: ";
	// for (int i = 0; i < dst.size(); ++i) {
	// 	cout << dst[i] << " ";
	// }
	// cout << endl;

	return 0;
}
