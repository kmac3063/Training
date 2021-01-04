#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

vector<vector<int>> g;
vector<int> used;
vector<int> ord;

void dfs(int i) {
    used[i] = 1;
    for (auto j : g[i]) {
        if (!used[j])
            dfs(j);
    }
    ord.push_back(i);
}

pair<int, int> m(int a, int b) {
    return pair<int, int>(min(a, b), max(a, b));
}

pair<int, int> m(pair<int, int> p) {
    int a = p.first, b = p.second;
    return m(a, b);
}

int main() {
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        ll S; cin >> S;
        g = vector<vector<int>>(n, vector<int>());
        ord = vector<int>();
        map<pair<int, int>, pair<ll, ll>> prs;

        vector<int> w(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b >> w[i];
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
            prs[m(a, b)] = {w[i], -1};
        }

        used = vector<int>(n, 0);
        dfs(0);

//        reverse(ord.begin(), ord.end());
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[ord[i]] = i;
        }
        vector<ll> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            int v = ord[i];
            for (auto v1 : g[v]) {
                if (pos[v1] > pos[v]) {
                    if (cnt[v] == 0) cnt[v] = 1;
                    cnt[v1] += cnt[v];
                }
            }
        }

        ll ts = 0;
        set<pair<ll, int>> s;
        for (auto [a, p] : prs) {
            ts += p.first * p.second;
            s.insert({p.first * p.second, a.first});
        }

        int ans = 0;
        while (ts > S) {
            auto top = *s.begin();
            s.erase(s.equal_range(top).first);

            ll b = top.second.first;
            ll st = b / 2;

            ll oldPrice = top.first;
            ll newPrice = st * top.second.second;

            ts -= (oldPrice - newPrice);

            top.first = newPrice;
            top.second.first = st;

            s.insert(top);
            ans++;
        }
        cout << ans << endl;
    }
    /*
4 5
1 2 5
2 3 5
3 4 100

100
7 8
1 2 2
2 3 2
2 4 2
1 7 2
7 5 2
7 6 2

5 5
1 2 1212
1 3 2
1 4 2
1 5 2
     */
    return 0;
}