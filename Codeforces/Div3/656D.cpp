#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;


int ans(string& s, const char& ch) {
    if (s.size() == 1) {
        return s[0] != ch;
    }
    string s1, s2;

    for (int i = 0; i < s.size(); ++i) {
        if (i < (s.size() + 1) / 2)
            s1.push_back(s[i]);
        else
            s2.push_back(s[i]);
    }
    int a = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != ch)
            a++;
    }
    a += ans(s2, ch + 1);

    int b = 0;
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] != ch)
            b++;
    }
    b += ans(s1, ch + 1);

    return min(a, b);
}

int main() {
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << ans(s, 'a') << endl;
    }

    return 0;
}