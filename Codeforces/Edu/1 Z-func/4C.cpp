#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto zet(string s) {
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

int main() {
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        auto z = zet(s);
        vector<int> ans(s.size() + 1);
        vector<int> v(z.size());
        for (int i = 0; i < z.size(); ++i) {
            v[z[i]]++;
        }
        int k = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            k += v[i];
            ans[i] = k;
        }
        for (int i = 1; i < ans.size(); ++i) {
            cout << ans[i] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}