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
    while (n) {
        ans += n & 1;
        n >>= 1;
    }
    cout << ans;
}

