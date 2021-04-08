#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>

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
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, x; cin >> n >> x;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F;
        v[i].S = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int find = x - v[i].F;
        int l = 0, r = n - 1;
        while (l < r) {
            if (l == i || r == i) {
                if (l == i) l++;
                if (r == i) r--;
                continue;
            }
            if (v[l].F == find - v[r].F) {
                cout << v[l].S << " " << v[r].S << " " << v[i].S << endl;
                return 0;
            } else if (v[l].F < find - v[r].F) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
