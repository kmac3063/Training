#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector<vector<pair<int, int>>> dp;
vector<int> v;

pair<int, int> ans(int l, int r) {
    //cout << l << ' ' << r << endl;
    if (dp[l][r] != make_pair(-1, -1)) {
        return dp[l][r];
    }
    if (r - l == 1) {
        return dp[l][r] = {max(v[l], v[r]), min(v[l], v[r])};
    }
    if (ans(l + 1, r).second + v[l] > ans(l, r - 1).second + v[r]) {
        return dp[l][r] = {ans(l + 1, r).second + v[l], ans(l + 1, r).first};
    } else {
        return dp[l][r] = {ans(l, r - 1).second + v[r], ans(l, r - 1).first};
    }
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    dp.resize(n, vector<pair<int, int>>(n, {-1, -1}));
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ans(0, n-1);
    auto p = dp[0][n - 1];
    if (p.first == p.second) {
        cout << 0;
    } else {
        cout << (p.first > p.second ? 1 : 2);
    }

    return 0;
}