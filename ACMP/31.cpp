#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll fact(int n) {
    int a = 1;
    for (int i = 2; i <= n; i++) {
        a *= i;
    }
    return a;
}

long long C(int n, int k) {
    return fact(n) / (fact(n - k) * fact(k));
}

ll ans(int n, int k) {
    if (n == 1 && k == 0) {
        return 0;
    }
    if (n == k)
        return 1;
    ll res = C(n, k);
    ll f = fact(n - k);
    for (int i = 1; i <= n - k; i++) {
        f -= ans(n - k, i);
    }
    return res * f;
}


int main() {
    int n; cin >> n;
    int k; cin >> k;
    cout << ans(n, k);
}
