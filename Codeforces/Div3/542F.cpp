#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define ll long long

using namespace std;

ll solve(ll h0, const vector<vector<ll>>& v) {
    int n = v.size();
    int m = v[0].size();
    vector<vector<ll>> dp(n, vector<ll>(m, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll h = h0 + i + j;
            if (j + 1 < m && v[i][j + 1] > h) {
                ll d = v[i][j + 1] - h - 1;
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + d);
            }
            if (i + 1 < n && v[i + 1][j] > h) {
                ll d = v[i + 1][j] - h - 1;
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d);
            }
        }
    }
    return dp.back().back();
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i][j];
            }
        }
        ll ans = 1e18;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] - i - j <= v[0][0]) {
                    ll d = v[0][0] - (v[i][j] - i - j);
                    ans = min(ans, solve(v[i][j] - i - j, v) + d);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
