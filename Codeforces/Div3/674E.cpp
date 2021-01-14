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
    vi A(3), B(3);
    read(A);
    read(B);
//    о       победа проигрыш
//    0      1       2
//    1      2       3
//    камень ножницы бумага
//    ножницы бумага камень
//    бумага камень ножницы
    vector<vi> v1 = {{0, 0}, {1, 1}, {2, 2}, {0, 2}, {1, 0}, {2, 1}};
    sort(all(v1));
    int mn = INT32_MAX;
    do {
        auto a = A, b = B;
        fch(p, v1) {
            int i1 = p[0], i2 = p[1];
            int t = min(a[i1], b[i2]);
            a[i1] -= t, b[i2] -= t;
        }
        mn = min(mn, min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]));
    } while (next_permutation(all(v1)));

    prs(mn), prs(min(A[0], B[1]) + min(A[1], B[2]) + min(A[2], B[0]));
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}