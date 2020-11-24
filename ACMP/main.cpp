#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool check(string s) {
    int i = 0;
    if (s[i] == '-') i++;
    if (i < s.size() && '0' <= s[i] && s[i] <= '9') {
        while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
            i++;
        }
    } else {
        return 0;
    }
    if (s[i] != '+' && s[i] != '-' && s[i] != '/' && s[i] != '*')
        return 0;
    i++;
    if (i < s.size() && s[i] == '-') i++;
    if (i < s.size() && '0' <= s[i] && s[i] <= '9') {
        while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
            i++;
        }
    } else {
        return 0;
    }
    if (s[i] != '=')
        return 0;
    i++;
    if (i < s.size() && s[i] == '-') i++;
    if (i < s.size() && '0' <= s[i] && s[i] <= '9') {
        while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
            i++;
        }
    } else {
        return 0;
    }

    return i == s.size();
}

int main() {
    string s;
    cin >> s;
    if (s.size() < 5 || check(s) == 0) {
        cout << "ERROR"; return 0;
    }
    int i = 0;
    int ma = 0;
    if (s[i] == '-') {
        ma = 1;
        i++;
    }
    while ('0' <= s[i] && s[i] <= '9') {
        i ++;
    }
    int a = stoi(s.substr(ma, i - ma));
    if (ma) a=-a;
    char ch = s[i++];
    int j = i;
    int mb = 0;
    if (s[j] == '-') {
        mb = 1;
        i++;j++;
    }

    while ('0' <= s[i] && s[i] <= '9') {
        i++;
    }
    int b = stoi(s.substr(j, i - j));
    if (mb) b = -b;
    i++;
    int mc = 0;
    if (s[i] =='-') {
        i++;
        mc = 1;
    }
    int c = stoi(s.substr(i, s.size() - i));
    if (mc) c = -c;
    int c1;
    switch(ch) {
        case '+':
            c1 = a + b;
            break;
        case '-':
            c1 = a - b;
            break;
        case '*':
            c1 = a * b;
            break;
        case '/':
            if (b == 0) {
                cout << "NO";
                return 0;
            }
            if (c *b == a) {
                cout << "YES";
            } else {
                cout << "NO";
            }
            return 0;

            break;
    }

    cout << ((c1 == c) ? "YES" : "NO");
    return 0;
}

