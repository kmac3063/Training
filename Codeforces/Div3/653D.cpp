#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto& el : v) {
            cin >> el;
            el %= k;
            el = k - el;
            if (el == k) el = 0;
        }
        sort(v.begin(), v.end());
        vector<pair<ll, ll>> v1 = {{v[0], 1}};
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                v1.back().second++;
            } else {
                v1.push_back({v[i], 1});
            }
        }

        ll ans = 0;
        ll x = 0;
        if (v1[0].first == 0) v1[0].second = 0;
        while (1) {
            int b = 0;
            for (int j = 0; j < v1.size(); ++j) {
                if (v1[j].second) {
                    ans += v1[j].first - x + 1;
                    x = v1[j].first + 1;
                    v1[j].second--;
                    if (v1[j].second) b = 1;
                }
            }
            if (!b)
                break;
            ans += k - x;
            x = 0;

        }
        cout << ans << endl;
    }
    return 0;
}