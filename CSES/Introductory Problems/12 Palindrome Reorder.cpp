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
    string s; cin >> s;
    map<char, int> m;
    fch(ch, s) m[ch]++;
    int even = 0;
    int odd = 0;
    char ch = 0;
    fch(p, m) {
        even += p.S % 2 == 0;
        odd += p.S % 2 == 1;
        if (p.S % 2 == 1) {
            ch = p.F;
        }
    }
    if (sz(s) % 2 == 0 && odd > 0 || sz(s) % 2 && odd > 1) {
        pr("NO SOLUTION");
        return 0;
    }
    string ans(sz(s), 0);
    if (odd) {
        ans[ans.size() / 2] = ch;
        m[ch]--;
    }
    int i = 0;
    fch(p, m) {
        while (p.S) {
            ans[i] = ans[sz(s) - 1 - i] = p.F;
            i++;
            p.S -= 2;
        }
    }
    pr(ans);

    return 0;
}
