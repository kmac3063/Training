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
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += i + n / i;
            if (i * i == n)
                ans -= i;
        }
    }
    cout << ans;
}

