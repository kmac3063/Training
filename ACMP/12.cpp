#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct P {
    double x, y;
    P(double x, double y) : x(x), y(y) {}
    P(){}

    P operator-(P& a) {
        return P(x - a.x, y - a.y);
    }
};

double cP(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        P p; cin >> p.x >> p.y;
        vector<P> v(4);
        for (int i = 0; i < 4; ++i) {
            cin >> v[i].x >> v[i].y;
        }

        double area = abs(cP(v[1] - v[0], v[3] - v[0])) * 2;
        double areaT = 0;
        for (int i = 0; i < 4; ++i) {
            areaT += abs(cP(v[i] - p, v[(i + 1) % 4] - p));
        }

        ans += abs(areaT - area) < 1e-6;
    }
    cout << ans;
}
