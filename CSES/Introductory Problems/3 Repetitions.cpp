#include <iostream>

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
//    int n; cin >> n;
    int mt = 1, mx = 1;
    string s; cin >> s;
    for (int i = 1; i < sz(s); ++i) {
        if (s[i] == s[i - 1]) {
            mt ++;
        } else {
            mt = 1;
        }
        mx = max(mx, mt);
    }
    pr(mx);
    return 0;
}
