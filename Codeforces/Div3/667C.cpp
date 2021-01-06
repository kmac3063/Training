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
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
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

int main() {
    int _; cin >> _;
    while (_--) {
        ll n, x, y; cin >> n >> x >> y;
        ll d = y - x;
        ll mn = INT64_MAX;
        ll dl = -1;
        for (ll i = 0; i < n - 1; i++) {
            for (ll j = i + 1; j < n; j++) {
                ll di = j - i;
                if (d % di == 0) {
                    ll delta = d / di;
                    ll ii = n - j - 1;
                    ll lastEl = y + ii * delta;
                    ll fEl = y - j * delta;
                    if (fEl > 0 && lastEl < mn) {
                        mn = lastEl;
                        dl = delta;
                    }
                }
            }
        }
        vll v(n);
        for (int i = n - 1; i >= 0; i--) {
            v[i] = mn;
            mn -= dl;
        }
        fori(i, 0, n) {
            prs(v[i]);
        }
        pr("");
    }
    return 0;
}