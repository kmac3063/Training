#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(v[0] - v[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + 3 * abs(v[i] - v[i - 2]));
    }
    cout << dp.back();
}