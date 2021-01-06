#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <cmath>

using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define all(x) x.begin(), x.end()
#define rev reverse
#define pr(a) cout << a << endl
#define prs(a) cout << a << ' '
#define fori(i, a, n) for (int i = a; i < n; i++)
#define fch(a, v) for (auto& a : v)
#define sz(x) x.size()
#define ins insert

vector<vector<int>> g;
vi used;

void dfs(int i) {
    used[i] = 1;
    fch(v, g[i]) {
        if (!used[v])
            dfs(v);
    }
}

int main() {
    int _; cin >> _;
    while (_--) {
        int n, m; cin >> n >> m;
        g = vector<vector<int>>(n, vector<int>());
        used = vi(n);
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            a--, b--;
            g[a].pb(b), g[b].pb(a);
        }

        dfs(0);
        if (count(used.begin(), used.end(), 0)) {
            cout << "NO\n"; continue;
        }
        used.assign(n, 0);

        vi put(n);
        set<int> ans;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (used[top]) continue;
            used[top] = 1;
            if (put[top]) {
                fch(i, g[top]) {
                    if (!put[i]) {
                        q.push(i);
                    }
                }
            } else {
                ans.ins(top);
                put[top] = 1;
                fch(i, g[top]) {
                    q.push(i);
                    put[i] = 1;
                }
            }
        }

        pr("YES");
        pr(sz(ans));
        fch(i, ans) {
            prs(i + 1);
        }
        pr("");
    }
    return 0;
}