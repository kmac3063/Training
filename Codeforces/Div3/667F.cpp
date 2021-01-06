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
    int _; //cin >> _;
    _ = 1;
    while (_--) {
        int n, k;
        cin >> n >> k;
        string s1, s2; cin >> s1 >> s2;
        vector<vvi> dp(n + 1, vvi(k + 1, vi(n + 1, INT32_MIN)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int ck = 0; ck <= k; ck++) {
                for (int cnt0 = 0; cnt0 <= n; cnt0++) {
                    int e0 = s1[i] == s2[0];
                    int e1 = s1[i] == s2[1];
                    int e01 = s2[0] == s2[1];

                    dp[i + 1][ck][cnt0 + e0] = max(dp[i + 1][ck][cnt0 + e0], dp[i][ck][cnt0] + (e1 ? cnt0 : 0));
                    if (ck < k) {
                        dp[i + 1][ck + 1][cnt0 + 1] = max(dp[i + 1][ck + 1][cnt0 + 1],
                                                          dp[i][ck][cnt0] + (e01 ? cnt0 : 0));
                        dp[i + 1][ck + 1][cnt0 + e01] = max(dp[i + 1][ck + 1][cnt0 + e01],
                                                            dp[i][ck][cnt0] + cnt0);
                    }

                }
            }
        }
        int mx = -1;
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                mx = max(mx, dp[n][i][j]);
            }
        }
        pr(mx);
//        dp[i][шагов][s2[0]];
    }
    return 0;
}