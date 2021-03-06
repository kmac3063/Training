#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define all(x) x.begin(), x.end()
#define rev reverse
#define pr(a) cout << a << endl
#define prs(a) cout << a << ' '
#define fori(i, a, n) for (int i = a; i < n; i++)
#define fch(a, v) for (auto& a : v)
#define sz(x) x.size()
#define ins insert
#define read(v) fch(_0, v) {cin >> _0;}

#define M (int)(1e9+7)

int main() {
    int n; cin >> n;
    vi v(n);
    int b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] >= 0) {
            b = 1;
        }
    }
    if (!b) {
        cout << *max_element(all(v));
        return 0;
    }

    ll ans = -1;
    ll ans_ = -1;
    for (int i = 0; i < n; ++i) {
        if (ans < 0) ans = 0;
        ans += v[i];
        ans_ = max(ans_, ans);
    }
    cout << ans_;

    return 0;
}
