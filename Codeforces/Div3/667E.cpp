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

int main() {
    int _; cin >> _;
    while (_--) {
       int n, k;
       cin >> n >> k;
       vi v(n);
       read(v);
       auto vy = v;
       read(vy);
       sort(all(v));

        vi dp(n);
        dp.back() = 1;
        for (int i = n - 2; i>=0; i--) {
           auto l = lower_bound(all(v), v[i]);
           auto r= upper_bound(all(v), v[i] + k);
           dp[i] = max(dp[i + 1], r - l);
        }

        int ans = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            auto l = lower_bound(all(v), v[i]);
            auto r = upper_bound(all(v), v[i] + k);

            ans = max(ans, r - l + (r == v.end() ? 0 : dp[r - v.begin()]));
        }
        pr(ans);
    }
    return 0;
}