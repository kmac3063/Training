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
    int n, m;
    cin >> n >> m;
    if (m > n) {
        cout << 0; return 0;
    }
    if (m == 0) {
        cout << 1; return 0;
    }
    if (m == 1) {
        cout << n; return 0;
    }

    int ans = 0;
    int k = m;
    for (int space = 0; space < n; ++space) {
        k = m + space * (m - 1);
        if (k > n) break;
        ans += n - k + 1;
    }
    cout << ans;
}

