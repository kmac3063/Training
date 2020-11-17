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
    int ax, ay, bx, by, x, y;
    cin >> ax >> ay >> bx >> by >> x >> y;
    if (ax == bx) {
        cout << 2 * ax - x << ' ' << y;
    } else {
        cout << x << ' ' << 2 * ay - y;
    }
}