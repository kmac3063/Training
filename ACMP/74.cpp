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

int main() {
    int m, n;
    cin >> n >> m;
    if (m == 1) {
        cout << n;
        return 0;
    }
    int ans = 0;
    while (m % 2) {
        ans += n /= 2;
        m = (m + 1)  / 2;
    }
    ans += m / 2;
    cout << ans;
    return 0;
}