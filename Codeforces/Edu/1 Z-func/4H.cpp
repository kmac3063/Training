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

ll sum (ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}
int main() {
    string s; cin >> s;
    ll ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        string_view sv(s);
        sv.remove_prefix(i);
        auto z = zet(sv);
        int mx = *max_element(z.begin(), z.end());
        ans += sum(mx + 1, z.size());
    }
    cout << ans;
    return 0;
}

//7 10
//1 2 3 4 5 6 6