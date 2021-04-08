#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>

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

bool f(const pair<int, int>& a, const pair<int, int>& b) {
    return a.S < b.S;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll> pref(n);
    pref[0] = v[0];
    map<ll, int> m;
    m[0]++;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        pref[i] = (i == 0 ? 0 : pref[i - 1]) + v[i];

        if (m[pref[i] - x]) {
            ans++;
        }
        m[pref[i]]++;
    }

    cout << ans;

    return 0;
}
