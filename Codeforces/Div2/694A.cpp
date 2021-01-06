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
        ll n, x; cin >> n >> x;
        vll v(n);
        ll sum = 0;
        ll mn = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
            mn += (v[i] + x - 1) / x;
        }
        cout << (sum + x - 1) / x << ' ' << mn << endl;


    }
    return 0;
}