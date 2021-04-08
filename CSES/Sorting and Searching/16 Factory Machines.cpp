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
    ll n, target;
    cin >> n >> target;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll l = 0, r = v[0] * target;

    bool (*f)(const vector<ll>& v, ll m, ll target) = [](const vector<ll>& v, ll m, ll target) -> bool {
        ll ans = 0;
        for (auto& el: v) {
            if (ans >= target - m / el) {
                return true;
            }
            ans += m / el;
        }
        return ans >= target;
    };

    while (l != r - 1) {
        ll m = (l + r) / 2;
        if (!f(v, m, target)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}
