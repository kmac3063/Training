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
    ll n;
    cin >> n;
    if (n * (n + 1) % 4 != 0) {
        pr("NO");
        return 0;
    }
    ll need = n * (n + 1) / 4;
    vll f, s;
    for (ll i = n; i > 0; i--) {
        if (need - i >= 0) {
            need -= i;
            f.pb(i);
        } else {
            s.pb(i);
        }
    }
    pr("YES");
    pr(sz(f));
    fch(e, f) prs(e);
    pr("");
    pr(sz(s));
    fch(e, s) prs(e);

    return 0;
}
