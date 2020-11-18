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

ll f(ll n, ll m) {
    return 19 * m + (n + 239) * (n +366) / 2;
}

int main() {
    vector<bool> erat(50001 * 2);
    erat[1] = 1;
    for (int i = 2; i < erat.size(); ++i) {
        for (int j = 2 * i; j < erat.size(); j += i) {
            erat[j] = 1;
        }
    }
    int n; cin >> n;
    int ans = 0;
    for (int i = n + 1; i < 2 * n; ++i) {
        ans += erat[i] == 0;
    }
    cout << ans;
    return 0;
}
