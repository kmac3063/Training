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
        string s, t;
        cin >> s >> t;
        auto z = zet(t + s + s);
        int ans = -1;
        for (int i = t.size(); i < z.size(); ++i) {
            if (z[i] >= t.size()) {
                ans = i - t.size();
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}