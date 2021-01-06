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
        int n, x;
        cin >> n >> x;
        ll sum = 0;
        vector<pii> v;
        fori(i, 0, n) {
            int t; cin >> t;
            v.push_back({t, 1});
        }
        int i = 0;
        while (1) {
            if (v[i].first % x)
                break;
            sum += (v[i].first * v[i].second);
            v.push_back({v[i].first / x, x * v[i].second});
            i++;
        }
        while (i != sz(v)) {
            sum += v[i].first * v[i].second;
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}