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
    int n; cin >> n;
    if (!n) {
        cout << 0;
        return 0;
    } else if (n == 1) {
        int t; cin >> t; cout << t;
        return 0;
    }
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int i = 0;
    int cost = 0;
    int first = 1;
    int k = 0;
    while (i != n - 1) {
        while (v[k].second < i) {
            k++;
        }
        cost += (v[k].second - i + first) * v[k].first;
        first = 0;

        i = v[k].second;
        k++;
    }
    cout << cost;
}