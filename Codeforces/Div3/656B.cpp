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
        vector<int> v(2 * n + 1);
        vector<int> ans;
        for (int i = 0; i < 2 * n; ++i) {
            int t; cin >> t;
            if (v[t] == 0) {
                ans.push_back(t);
            }
            v[t] = 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}