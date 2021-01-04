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
        map<int, set<int>> m;
        map<int, int> m1;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sm = v[i] + v[j];
                if (m[sm].find(i) == m[sm].end() && m[sm].find(j) == m[sm].end()) {
                    m[sm].insert(i);
                    m[sm].insert(j);
                    m1[sm]++;
                }
            }
        }
        int mx = -1;
        for (auto p : m1) {
            mx = max(mx, p.second);
        }
        cout << max(mx, 0) << endl;
    }

    return 0;
}