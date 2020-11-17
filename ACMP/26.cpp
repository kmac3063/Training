#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int len(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int main() {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int dist = len({x1, y1}, {x2, y2});
    if (dist > (r1 + r2) * (r1 + r2) || dist < (r1 - r2) * (r1 - r2)) {
        cout << "NO";
    } else {
        cout << "YES";
    }

}

