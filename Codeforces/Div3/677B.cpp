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
    vector<int> v(n);
    read(v);
    vi ind1;
    for (int i = 0; i < n; ++i) {
        if (v[i]) ind1.pb(i);
    }
    int ans = 1e9;
    fch(ind, ind1) {
        int t = 0;
        int fst = 0;
        for (int i = 0; i < ind; ++i) {
            if (!v[i]) {
                if (fst)
                    t++;
            }
            if (v[i]) fst = 1;
        }
        fst = 0;
        for (int i = n - 1; i > ind ; i--) {
            if (!v[i] && fst) t++;
            if (v[i]) fst = 1;
        }
        ans = min(ans, t);
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