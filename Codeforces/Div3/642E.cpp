#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define ll long long

using namespace std;

int solve(const string& s) {
    int all = count(s.begin(), s.end(), '1');
    int pref = 0;
    vector<int> dp(s.size());
    int ans = all;
    for (int i = 0; i < s.size(); ++i) {
        pref += s[i] == '1';
        if (i == 0)
            dp[i] = pref ^ 1;
        else
            dp[i] = min(dp[i - 1], pref - (s[i] == '1')) + (s[i] != '1');

        ans = min(ans, dp[i] + all - pref);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s; cin >> n >> k >> s;
        vector<string> v(k);
        for (int i = 0; i < s.size(); ++i) {
            v[i % k].push_back(s[i]);
        }
        int cnt = count(s.begin(), s.end(), '1');
        int ans = 1e9;
        for (auto& it : v) {
            ans = min(ans, solve(it) + (cnt - count(it.begin(), it.end(), '1')));
        }
        cout << ans << endl;
    }
    return 0;
}