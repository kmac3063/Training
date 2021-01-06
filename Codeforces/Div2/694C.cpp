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
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
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

int main() {
    int _; cin >> _;
    while (_--) {
        int n, m; cin >> n >> m;
        vi fr(n);
        for (int i = 0; i < n; ++i) {
            cin >> fr[i];
            fr[i] --;
        }

        vi price(m);
        for (int i = 0; i < m; ++i) {
            cin >> price[i];
        }
        sort(all(fr));
        rev(all(fr));
        ll sum = 0;
        int p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (p1 <= fr[i] && price[p1] < price[fr[i]]) {
                sum += price[p1];
                p1++;
            } else {
                sum += price[fr[i]];
            }
        }
        pr(sum);
    }
    return 0;
}