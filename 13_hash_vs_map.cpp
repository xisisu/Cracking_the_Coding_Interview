#include <set>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

int main() {
	pair<int, int> p1(1, 1);
	pair<int, int> p2(1, 2);
	
	set< pair<int, int> > s;
	s.insert(p1);
	s.insert(p2);
	
	map<int, int> m;
	m.insert(p1);
	m.insert(p2);
	
	cout << "Set size = " << s.size() << "\nMap size = " << m.size() << endl;

	return 0;
}