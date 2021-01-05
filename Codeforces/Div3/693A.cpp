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
        int a, b, c;
        cin >> a >> b >> c;
        int a1 = 0;
        int k = 1;
        while (a % 2 == 0) {
            a1 += k;
            k *= 2;
            a /= 2;
        }
        int b1 = 0;
//         k = 1;
        while (b % 2 == 0) {
            b/= 2;
            b1 += k;
            k *= 2;
        }
        if (1 + a1 + b1 >= c) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}