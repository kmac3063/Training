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
    vll v(n); read(v);
    vll b(1 << 20);
//    for (int i = 0; i < n; ++i) {
//        b[1 << i] = v[i];
//    }
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) {
                b[i | (1 << j)] = b[i] + v[j];
            }
        }
    }
    ll ans = INT64_MAX;
    for (int i = 0; i < b.size(); ++i) {
       ans = min(ans, abs(b[i] - b[~i & 0xFFFFF]));
    }

    pr(ans);
    return 0;
}
