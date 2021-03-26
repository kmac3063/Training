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
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);

    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> dist;
    dist.ins(x);
    lights.ins(0);
    lights.ins(x);
    for (int i = 0; i < n; ++i) {
        int t = 0; cin >> t;
        auto it2 = lights.lower_bound(t);
        auto it1 = prev(it2);
        dist.erase(dist.find(*it2 - *it1));
        dist.ins(t - *it1);
        dist.ins(*it2 - t);

        lights.ins(t);

        cout << *prev(dist.end()) << endl;
    }
    return 0;
}
