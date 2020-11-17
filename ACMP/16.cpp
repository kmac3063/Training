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
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(N+1));
    for (int i = 0; i <= N; ++i) {
        dp[i][i] = 1;
    }

    for (int n = 2; n <= N; ++n) {
        for (int last = 1; last < n; ++last) {
            int sum = 0;
            for (int l1 = last + 1; l1 <= n - last; ++l1) {
                sum += dp[n - last][l1];
            }
            dp[n][last] += sum;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += dp[N][i];
    }
    cout << ans;
}

