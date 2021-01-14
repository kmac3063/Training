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
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define ins insert
#define pb push_back
#define rev reverse

#define all(x) x.begin(), x.end()
#define pr(a) cout << a << endl
#define prs(a) cout << a << ' '
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fch(a, v) for (auto& a : v)
#define sz(x) x.size()
#define read(v) fch(_0, v) {cin >> _0;}

void solve() {
   int n; cin >> n;
   if (n == 1) {
       pr(0);
       return;
   }
   int a = sqrt(n) - 1;
   if (a == 0) a = 1;
   int b = a + 1;
   int c = a + 2;
   int mn = 1e9 + 1;
   if (a * ((n + a - 1)/ a) >= n) {
       mn = min(mn, a - 1 + (n + a - 1) / a);
       a = b;
   }
    if (a * ((n + a - 1)/ a) >= n) {
        mn = min(mn, a - 1 + (n + a - 1) / a);
        a = c;
    }
    if (a * ((n + a - 1)/ a) >= n) {
        mn = min(mn, a - 1 + (n + a - 1) / a);
        b = a;
    }
   pr(mn - 1);
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}