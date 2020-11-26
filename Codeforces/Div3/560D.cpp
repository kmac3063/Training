#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define ll long long

using namespace std;

auto get(ll n) {
    vector<ll> det;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            det.push_back(i);
            if (i * i != n) {
                det.push_back(n / i);
            }
        }
    }
    sort(det.begin(), det.end());
    return det;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll ans = v.front() * v.back();
        auto list = get(ans);
        if (v == list) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
