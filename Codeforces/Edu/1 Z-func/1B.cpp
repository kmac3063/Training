#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z(string& s) {
    int l, r = -1;
    vector<int> zet(s.size());
    zet[0] = 0;
    int i = 1;
    while (i < s.size()) {
        if (i < r) {
            zet[i] = min(zet[i - l], r - i + 1);
        }

        while (i < s.size() && s[zet[i]] == s[i + zet[i]]) {
            zet[i]++;
        }

        if (i + zet[i] - 1 > r) {
            r = i + zet[i] - 1;
            l = i;
        }
        i++;
    }
    return zet;
}

int ans(string& s) {
    auto v = z(s);
    int ans = 0;

    vector<int> pref(v.size());
    pref[v.size() - 1] = v.back();
    for (int i = v.size() - 2; i >= 0; --i) {
        pref[i] = pref[i + 1] + (i + v[i] == s.size());
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) continue;
        ans += v[i] - pref[v.size() - v[i]];
    }

    for (int i = 0; i < v.size(); ++i) {
        if (i + v[i] != v.size())
            ans++;
    }

    return ans - 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a = ans(s);
        reverse(s.begin(), s.end());
        int b = ans(s);
        cout << a + b << endl;
    }
    return 0;
}