#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <cmath>

using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define ins insert
#define pb push_back
#define rev reverse

#define all(x) x.begin(), x.end()
#define pr(a) cout << a << endl
#define prs(a) cout << a << ' '
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fch(a, v) for (auto& a : v)
#define sz(x) x.size()
#define read(v) fch(_0, v) {cin >> _0;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<pii, pii>> v(n);
    bool bd = 0, ba;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F.F >> v[i].F.S >> v[i].S.F >> v[i].S.S;
        if (v[i].F.S == v[i].S.F) bd = 1;
    }
    if (m % 2 == 1 || bd == 0) {
        pr("NO");
        return;
    }
    pr("YES");
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}