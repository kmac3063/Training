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
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int n, m;
        cin >> n >> m;
        cout << f(n, m) << endl;
    }
    return 0;
}
