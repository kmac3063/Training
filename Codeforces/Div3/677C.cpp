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
    int mx = *max_element(all(v));
    int ind = max_element(all(v)) - v.begin();
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == mx && (i > 0 && v[i] > v[i - 1] || v[i] > v[i + 1] && i < n - 1)) {
            b = 1;
            ind = i;
            break;
        }
    }
    if (b) pr(ind + 1);
    else pr(-1);
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}