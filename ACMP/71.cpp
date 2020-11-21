#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int s(vector<int>& v, int a) {
    int a1 = 0, b = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (a & (1 << i)) {
            a1 += v[i];
        } else {
            b += v[i];
        }
    }
    return abs(a1 - b);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sm += v[i];
    }
    vector<int> dp(1 << n);
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) == 0) {
                dp[i | (1 << j)] = dp[i] + v[j];
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < dp.size(); ++i) {
        ans = min(ans, abs(sm - 2 * dp[i]));
    }
    cout << ans;

    return 0;
}