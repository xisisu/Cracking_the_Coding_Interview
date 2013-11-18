#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string toString(int num) {
    stack<int> s;
    string res;
    while (num != 0) {
        s.push(num & 0x01);
        num /= 2;
    }

    while (!s.empty()) {
        cout << s.top();
        res += '0'+s.top();
        s.pop();
    }
    cout << endl;

    return res;
}

int toInt(string s) {
    int sum = 0;
    int cur = 1;

    for (int i = s.size()-1; i >= 0; i--) {
        sum += (s[i]-'0')*cur;
        cur <<= 1;
    }

    return sum;
}