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

vector<int> zet(string s) {
    vector<int> z(s.size());
    int l = -1, r = -1;
    z[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    string pattern1 = ">>-->";
    string pattern2 = "<--<<";
    auto z1 = zet(pattern1 + s);
    auto z2 = zet(pattern2 + s);
    int ans = 0;
    for (int i = pattern1.size(); i < z1.size(); ++i) {
        if (z1[i] >= pattern1.size()) {
            ans++;
        }
        if (z2[i] >= pattern2.size()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}