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

int main() {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int r; cin >> r;
    int S1; cin >> S1;
    const double PI = 3.1415926535897;
    double S2 = 2 * PI * r * r;
    double d = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    if (d < 2 * r) {
        double f = 2 * acos(d / (2 * r));
        S2 -= (double)r * r * (f - sin(f));
    }
    if (S2 > S1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}