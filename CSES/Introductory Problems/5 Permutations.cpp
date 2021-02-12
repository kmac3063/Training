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
    if (n == 1) {
        pr(n);
    }
    else if (n <= 3) {
        pr("NO SOLUTION");
    } else if (n == 4) {
        pr("3 1 4 2");
    }
    else {
        for (int i = 1; i <= n; i += 2) {
            prs(i);
        }
        for (int i = 2; i <= n; i+= 2) {
            prs(i);
        }
    }
    return 0;
}
