#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int main() {
//    vector<int> v = {1, 2, 3};
//    auto it = v.begin();
//    it = next(it);
//    it = next(it);
//    it = next(it);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<pair<ll, ll>> v(n), h(n * 2);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
            h[i] = {v[i].first, i};
            h[n + i] = {v[i].second, -(i + 1)};
        }
        sort(h.begin(), h.end());
        vector<ll> ans(n, -2);

        ll m1 = INT64_MAX, m_i1;
        ll m2 = INT64_MAX, m_i2;

        int oldH = -1;
        for (int i = 0; i < 2 * n; ++i) {
            int ind = h[i].second;
            int we, he;
            if (ind < 0) {
                ind = -ind - 1;
                he = v[ind].second, we = v[ind].first;
            } else {
                he = v[ind].first, we = v[ind].second;
            }

            if (h[i].first == oldH) {
                if (m2 < we) {
                    ans[ind] = m_i2;
                }
            } else {
                if (m1 < we) {
                    ans[ind] = m_i1;
                }
            }

            if (h[i].first != oldH) {
                m2 = m1;
                m_i2 = m_i1;
            }
            if (we < m1) {
                m1 = we;
                m_i1 = ind;
            }

            oldH = h[i].first;
        }
        for (auto i : ans) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}