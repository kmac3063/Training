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
    vll v(n); read(v);
    sort(all(v));
    vll pref(n), rpref(n);
    pref[0] = 0;
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + i * (v[i] - v[i - 1]);
    }
    rpref[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        rpref[i] = rpref[i + 1] + (v[i + 1] - v[i]) * (n - i - 1);
    }
    ll ans = INT64_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, pref[i] + rpref[i]);
    }
    cout << ans;
    return 0;
}
