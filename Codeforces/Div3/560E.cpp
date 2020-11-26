#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i <n ; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <n ; ++i) {
        cin >> b[i];
    }
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        v[i] = (i + 1) * a[i] * (a.size() - i);
    }
    sort(v.begin(), v.end());
    sort(b.begin(), b.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + ((v[i]) % 998244353 * (b[i]) % 998244353) % 998244353) % 998244353;
    }
    cout << ans % 998244353 << endl;
    return 0;
}
