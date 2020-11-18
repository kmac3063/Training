#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

string mx(string s) {
    sort(s.begin(), s.end(), greater<char>());
    if (s[0] == '0') return "0";
    return s;
}

string mn(string s) {
    sort(s.begin(), s.end());
    if (s.back() == '0') return "0";
    if (s[0] == '0') {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != '0') {
                swap(s[i], s[0]);
                break;
            }
        }
    }
    return s;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int a;
    int b;
    if (s1[0] == '-') {
        a = -stoi(mn(s1.substr(1, s1.size() - 1)));
    } else {
        a = stoi(mx(s1));
    }

    if (s2[0] == '-') {
        b = -stoi(mx(s2.substr(1, s2.size() - 1)));
    } else {
        b = stoi(mn(s2));
    }

    cout << a - b;
}
