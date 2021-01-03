#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

vector<vector<int>> v;
vector<set<int>> my;
vector<int> topsort;
vector<int> used;
bool cycle;

void dfs(int i) {
    used[i] = 1;
    for (int j = 0; j < v[i].size(); j++) {
        if (!used[v[i][j]])
            dfs(v[i][j]);
    }
    topsort.push_back(i);
}

void newDfs(int i, int p) {
    used[i] = 1;
    for (int j = 0; j < v[i].size(); j++) {
        int to = v[i][j];
        if (to == p) continue;
        if (used[to] != 1) {
            my[i].insert(to);
            if (used[to] == 0)
            newDfs(to, i);
        }
    }
    used[i] = 2;
}

void cycleCheck(int i, int p) {
    if (cycle) return;
    used[i] = 1;
    for (auto& to: my[i]) {
        if (to == p) continue;
        if (used[to] == 0) {
            cycleCheck(to, i);
        } else if (used[to] == 1) {
            cycle = 1;
            return;
        }
    }
    used[i] = 2;
}

int main() {
    int _; cin >> _;
    while (_--) {
        int n, k;
        cin >> n >> k;
        set<pair<int, int>, greater<pair<int, int>>> s;
        vector<set<int>> v(n, set<int>());
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            v[a].insert(b);
            v[b].insert(a);
        }
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            if (v[i].size() == 1) {
                lst[*v[i].begin()]++;
            }
        }

        for (int i = 0; i < n; ++i) {
            s.insert({lst[i], i});
        }

        int ans = 0;
        while (s.begin()->first >= k) {
            auto a = *s.begin();
            if (s.begin()->first == 1 && v[a.second].size() == 1) {
                ans += k==1;
                break;
            }
            s.erase(s.begin());

            vector<int> toRemove;
            for (int to: v[a.second]) {
                if (toRemove.size() == k) break;
                if (v[to].size() == 1) {
                    toRemove.push_back(to);
                }
            }
            for (int i : toRemove) {
                v[a.second].erase(i);
            }
            a.first -= k;
            lst[a.second] -= k;
            s.insert(a);

            ans++;
            if (v[a.second].size() == 1) {
                int to =*v[a.second].begin();
                s.erase({lst[to], to});
                lst[to]++;
                s.insert({lst[to], to});
            }
        }
        cout << ans << endl;
    }

    return 0;
}