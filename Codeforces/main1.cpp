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
        int n, m; cin >> n >> m;
        v = vector<vector<int>>(n, vector<int>());
        my = vector<set<int>>(n, set<int>());
        used = vector<int>(n);
        topsort.clear();
        cycle = 0;

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> c >> a >> b;
            a--;b--;
            v[a].push_back(b);
            if (!c)
                v[b].push_back(a);
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs(i);
        }
        reverse(topsort.begin(), topsort.end());

        used.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!used[topsort[i]]) {
                newDfs(topsort[i], -1);
            }
        }

        used.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                cycleCheck(i, -1);
        }
        if (cycle) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (auto& it : my[i]) {
                    cout << i + 1<< ' ' << it + 1 << endl;
                }
            }
        }
    }

    return 0;
}