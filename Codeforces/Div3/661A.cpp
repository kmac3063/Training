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
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool b = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i + 1] - v[i] > 1)
                b = 1;
        }
        if (b) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}