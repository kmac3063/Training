#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

void move(vector<pair<int, int>>& v, int i) {
    auto t1 = v[i + 1];
    v[i + 1] = v[i];
    v[i] = v[i + 2];
    v[i + 2] = t1;
}

int main() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            int t; cin >> t;
            v[i] = {t, i};
        }
        auto v1 = v;
        stable_sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());
        vector<int> ans;
        for (int i = 0; i < v1.size() - 2; ++i) {
            int ind = v1[i].second;
            for (int j = 0; j < v.size() - i; ++j) {
                if (v[j].first == v1[i].first) {
                    ind = max(ind, j);
                    break;
                }
            }
            ind++;
            while (ind < v.size() - i) {
                int ti = max(0, ind - 2);
                ans.push_back(ti);
                move(v, ti);
                ind++;
            }
        }

        if (1/*v[0].first <= v[1].first*/) {
            cout << ans.size() << endl;
            for (auto& p : ans) {
                cout << p + 1 << ' ';
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}