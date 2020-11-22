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

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a = 0;
        cin >> a;
        char c; cin >> c;
        int b = 0;
        cin >> b;
        a = 60 * a + b;

        cin >> b;
        cin >> c;
        int d;
        cin >> d;
        b = 60 * b + d;
        v.push_back({a, 0});
        v.push_back({b, 1});
    }

    sort(v.begin(), v.end());
    int open = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second == 0) {
            open++;
        } else {
            open--;
        }
        ans = max(ans, open);
    }
    cout << ans;
}