#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

int main() {
    int _; cin >> _;
    while (_--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == z && x >= y) {
            cout << "YES\n" << x << ' ' << y << ' ' << y << endl;
        } else if (x == y && x >= z) {
            cout << "YES\n" << x << ' ' << z << ' ' << z << endl;
        } else if (y == z && y >= x) {
            cout << "YES\n" << y << ' ' << x << ' ' << x << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}