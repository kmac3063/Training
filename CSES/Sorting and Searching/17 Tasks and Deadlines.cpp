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
    ll n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
    }
    sort(all(v), [](auto p1, auto p2) -> auto {
       return p1.F < p2.F;
    });

    ll last = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += v[i].S - v[i].F - last;
        last += v[i].F;
    }
    cout << ans;
    return 0;
}
