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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            pr(0);
        } else if (i == 2) {
            pr(6);
        } else if (i == 3) {
            pr(28);
        } else {
            map<ll, ll> m = {
                    {2, 4},
                    {3, 8},
                    {4, (i - 4) * 4 + 4},
                    {6, (i - 4) * 4},
                    {8, (i - 4) * (i - 4)}
            };
            ll kv = i * i;
            ll ans = 0;
            for (auto [a, b] : m) {
                ans += b * (kv - 1 - a);
            }
            pr(ans / 2);
        }
    }
    return 0;
}
