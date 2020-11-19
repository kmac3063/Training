

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int eq(vector<char>& v1, vector<char>& v2) {
    int ans = 0;
    map<int, int> m;
    for (int i = 0; i < v1.size(); ++i) {
        m[v1[i]] = 1;
    }
    for (int i = 0; i < v2.size(); ++i) {
        ans += m[v2[i]];
    }
    return ans;
}
int main() {
    map<char, vector<char>> m;
    for (int i = 0; i < 10; ++i) {
        m[i + '0'] = {(char)('0' + i)};
        m['?'].push_back('0' + i);
    }
    for (int c = 'a'; c <= 'g'; c++) {
        for (int i = 0; i < 4; ++i) {
            m[c].push_back(c - 'a' + '0' + i);
        }
    }

    string s1, s2;
    cin >> s1 >> s2;
    int ans = 1;
    for (int i = 0; i < s1.size(); ++i) {
        ans *= eq(m[s1[i]], m[s2[i]]);
    }

    cout << ans;
    return 0;
}