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
    vector<pair<int, int>> v(2 * n);
    int k = 1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[n + i].first;
        v[i].second = -k, v[n + i].second = k;
        k++;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    vector<int> v1;
    int t = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (v[i].second < 0) {
            t++;
        } else {
            v1.erase(prev(v1.end()));
            t--;
        }
        ans = max(ans, t);
    }
    cout << ans;

    return 0;
}
