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

ll t(ll a, ll b, ll x, ll y, ll n) {
    if (a == b) {
        if (x > y) swap(x, y);
    }
    if (a - x <= n) {
        n -= (a - x);
        a = x;
    } else {
        a -= n;
        n = 0;
    }

    if (b - y <= n) {
        b = y;
    } else {
        b -= n;
    }

    return a * b;
}

int main() {
    int _; cin >> _;
    while (_--) {
        ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;

        pr(min(t(a, b, x, y, n), t(b, a, y, x, n)));
    }
    return 0;
}