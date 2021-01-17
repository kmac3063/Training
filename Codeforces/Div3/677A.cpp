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
    vector<int> v;
    int t = 0;
    int b = 1;
    while (b != 99999) {
        t = 10 * t + b;
        if (t > 1e4) {
            b++;
            t = 0;
        }
        else {
            v.pb(t);
        }
    }
    int ans = 0;
    for (int i = 0; i < sz(v); ++i) {
        ans += to_string(v[i]).size();
        if (v[i] == n)
            break;
    }
    pr(ans);
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}