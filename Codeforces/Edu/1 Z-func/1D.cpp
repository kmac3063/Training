#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define ll long long

using namespace std;

vector<int> zet(string s) {
    vector<int> z(s.size());
    int l = -1, r = -1;
    for (int i = 1; i < s.size(); i++) {
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
    int q;
    cin >> q;
    while (q--) {
        string s, s1;
        cin >> s >> s1;
        auto z = zet(s1 + s);
        vector<int> v;
        for (int i = s1.size(); i < z.size() ; i++) {
            if (z[i] >= s1.size()) {
                v.push_back(i - s1.size());
            }
        }
        auto sum = [](ll n) -> ll {
            return (1 + n) * n / 2;
        };
        if (v.empty()) {
            cout << sum(s.size()) << endl;
            continue;
        }
        ll ans = 0;

        ans += sum(v[0] + s1.size() - 2 + 1);
        ans += sum(s.size() - v.back() - 1);
        for (int i = 1; i < v.size(); i++) {
            int l = v[i - 1] + 1;
            int r = v[i] + s1.size() - 2;;
            ans += sum(r - l + 1);
        }
        if (s1.size() > 2)
            ans -= v.size() * sum(s1.size() - 2);
        cout << ans << endl;
    }

    return 0;
}
