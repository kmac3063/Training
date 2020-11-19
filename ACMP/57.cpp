#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cost(pair<int, int> p1, pair<int, int>& p2) {
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int main() {
    int n, c;
    double p;
    cin >> n >> c >> p;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    int x, y; cin >> x >> y;
    double minS = p + 1;
    for (int i = 0; i < n; ++i) {
        double tempS = 0;
        for (int j = 0; j < n; ++j) {
            int dx = v[i].first - v[j].first;
            int dy = v[i].second - v[j].second;
            tempS += sqrt(dx * dx + dy * dy);
        }
        int dx = v[i].first - x;
        int dy = v[i].second - y;
        tempS += sqrt(dx * dx + dy * dy);
        minS = min(tempS, minS);
    }
    if (c * minS <= p) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}