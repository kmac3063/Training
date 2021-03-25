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
    int n; cin >> n;
    vi v(n); read(v);

    map<int, int> m;
    int l = 0;
    int mx = -1;
    for (int r = 0; r < n; ++r) {
        m[v[r]]++;
        bool b = 0;
        if (m[v[r]] > 1) {
            b = 1;
        }
        while (b) {
            m[v[l]]--;
            if (m[v[l]] == 1) {
                b = 0;
            }
            l++;
        }

        mx = max(mx, r - l + 1);
    }
    cout << mx << endl;
    return 0;
}
