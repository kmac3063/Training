#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto Z(string s) {
    vector<int> z(s.size());
    z[0] = 0;
    int l, r = -1;
    for (int i = 1; i < s.size(); ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < s.size() && (s[z[i]] == s[i + z[i]] || s[z[i]] == '?')) {
            z[i]++;
        }

        if (z[i] + i - 1 > r) {
            r = z[i] + i - 1;
            l = i;
        }
    }
    return z;
}

int main() {
    int q; cin >> q;
    while (q--) {
        string s, p;
        cin >> s >> p;
        vector<int> ans;
        auto z = Z(p + s);
        for (int i = p.size(); i < z.size(); ++i) {
            if (z[i] >= p.size()) {
                ans.push_back(i - p.size());
            }
        }

        cout << ans.size() << endl;
        for (auto& a : ans) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}