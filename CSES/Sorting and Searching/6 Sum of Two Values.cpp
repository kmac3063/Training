#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
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
#define read(v) fch(_0, v) {cin >> _0;}

#define M (int)(1e9+7)

int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m[v[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        int find = x - v[i];
        if (v[i] == find) {
            if (m[find].size() > 1) {
                cout << m[find][0] + 1 << " " << m[find][1] + 1<< endl;
                return 0;
            }
        } else {
            if (!m[find].empty()) {
                cout << i + 1<< " " << m[find][0] + 1<< endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
