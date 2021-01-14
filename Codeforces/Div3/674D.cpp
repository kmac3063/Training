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
    int n; cin >> n;
    vi v(n);
    read(v);
    ll t = 0;
    set<ll> s;
    s.ins(t);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        t += v[i];
        if (s.size() && s.find(t) != s.end()) {
            ans++;
            s.clear();
            s.ins(0);
            t = v[i];
        }
        s.insert(t);
    }
    pr(ans);
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}