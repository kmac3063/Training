#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        vector<ll> res(n);
        for (ll i = n - 1;i>= 0; i--) {
            if (i + v[i] >= n) {
                res[i] = v[i];
            } else {
                res[i] = v[i] + res[i + v[i]];
            }
        }
        cout << *max_element(res.begin(), res.end()) << endl;
    }
    return 0;
}