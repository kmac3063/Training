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
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        ll minA = INT32_MAX;
        ll minB = minA;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            minA = min(minA, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            minB = min(minB, b[i]);
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll dA = a[i] - minA;
            ll dB = b[i] - minB;
            ans += max(dA, dB);
        }
        cout << ans << endl;
    }

    return 0;
}