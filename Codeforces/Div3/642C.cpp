#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll ans = 0;
        while (n != 1) {
            ans += (4*n - 4) * (n / 2);
            n -= 2;
        }
        cout << ans << endl;
    }
//    *****
//    *****
//    *****
//    *****
//    *****
    return 0;
}
