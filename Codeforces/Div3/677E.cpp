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

#define M (int)(1e9+7)

ll f(ll a) {
    if (a <= 1) return 1;
    return a * f(a - 1);
}

void solve() {
    int n; cin >> n;
    ll sp = f(n - 1) / (n / 2);
    pr(sp);
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}