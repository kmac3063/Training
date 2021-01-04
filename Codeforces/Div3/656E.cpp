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
vector<int> topsort;
vector<int> used;

void dfs(int i) {
    used[i] = 1;
    for (int j = 0; j < v[i].size(); j++) {
        if (!used[v[i][j]])
            dfs(v[i][j]);
    }
    topsort.push_back(i);
}

int main() {
    int _; cin >> _;
    while (_--) {
        int n, m; cin >> n >> m;
        v = vector<vector<int>>(n, vector<int>());
        vector<pair<int, int>> v1, v2;
        used = vector<int>(n);
        topsort.clear();

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> c >> a >> b;
            a--;b--;
            if (c == 1)
                v[a].push_back(b);
            v2.push_back({a, b});
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs(i);
        }
        reverse(topsort.begin(), topsort.end());
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[topsort[i]] = i;
        }
        bool b = 0;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                if (pos[i] > pos[v[i][j]]) {
                    b = 1;
                    break;
                }
            }
        }
        if (b) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (auto [x, y] : v2) {
                if (pos[x] < pos[y]) {
                    cout << x + 1 << ' ' << y + 1 << endl;
                } else {
                    cout << y + 1 << ' ' << x + 1 << endl;
                }
            }
        }
    }

    return 0;
}