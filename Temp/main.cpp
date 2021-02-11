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

#define M (int)(1e9+7)

void solve() {
    int n; cin >> n;
    vi v(n);
    read(v);
    vi dp(n);

    for (int i = 0; i < n; ++i) {
        dp[i] = INT32_MAX;
    }

    vi up(n, 0);
    for (int i = 0; i < n; i++) {
        int j = int (upper_bound (all(dp), v[i]) - dp.begin());
        // возрастает
        if (v[i] >= dp[j - 1]) {
            dp[j] = v[i];
            up[j] = 0;
        } else {
            if (up[j] == 0) {
                dp[j] = v[i];
                up[j] = 1;
            }

            //Убывает и 1
            if (up[j] == 1 && dp[j - 1] < v[i])
                dp[j - 1] = v[i];

        }

        //убывает и 0
    }

}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
