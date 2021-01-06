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

int main() {
    int _; cin >> _;
    while (_--) {
        string s; cin >> s;
        int r; cin >> r;
        int sum = 0;
        fch(ch, s) sum += ch - '0';
        ll steps = 0;
        int i = sz(s) - 1;
        ll ten = 1;
        while (sum > r) {
            sum -= s[i] - '0';
            steps += ten * ('9' + 1 - s[i]);
            ten *= 10;
            i--;
            if (i >= 0) {
                int j(i);
                while (j >= 0 && s[j] == '9') {
                    s[j] = '0';
                    j--;
                    sum -= 9;
                }
                if (j >= 0) {
                    s[j]++;
                    sum++;
                }
            }
        }
        pr(steps);
    }
    return 0;
}