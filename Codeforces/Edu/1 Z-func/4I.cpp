#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

auto zet(string_view s) {
    vector<int> z(s.size());
    int l, r = -1;
    for (int i = 1; i < s.size(); i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

auto inv(string v1, string v2) {
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

int main() {
    string s, p;
    cin >> s >> p;
    int k; cin >> k;
    auto z = zet(p + s);
    auto z_inv = zet(inv(p, s));
    auto obr = z;
    for (int i = p.size(); i < obr.size(); ++i) {
        obr[i] = z_inv[z_inv.size() - (i - p.size()) - 1];
    }
    vector<int> ans;
    for (int i = p.size(); i < z.size() - p.size() + 1; ++i) {
        if (z[i] + obr[i + p.size() - 1] + k >= p.size()) {
            ans.push_back(i - p.size());
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it + 1 << ' ';
    }
    return 0;
}

//7 10
//1 2 3 4 5 6 6