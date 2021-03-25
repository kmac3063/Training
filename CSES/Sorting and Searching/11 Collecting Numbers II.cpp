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


pair<int, int> m(int a, int b) {
    return {min(a, b), max(a, b)};
}

int main() {
    int n, m1; cin >> n >> m1;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F;
        v[i].S = i;
    }
    sort(all(v));
    int ans = 0;
    int last = n;
    for (int i = 0; i < n; ++i) {
        if (v[i].S < last) {
            ans++;
        }
        last = v[i].S;
    }

    vector<int> pos(n + 1);
//    pos[0] = -100;
    for (auto & i : v) {
        pos[i.S] = i.F;
    }


    for (int i = 0; i < m1; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);

        int self_a = pos[a];
        int prev_a = self_a - 1;
        int next_a = self_a + 1;
        int self_b = pos[b];
        int prev_b = self_b - 1;
        int next_b = self_b + 1;
        set<pair<int, int>> sp;
        if (a != n && a < v[next_a - 1].S) {
            ans++;
            sp.insert(m(a, v[next_a - 1].S));
        }
        if (sp.find(m(v[prev_a - 1].S, a)) == sp.end() && self_a != 1 && v[prev_a - 1].S < a) {
            ans++;

            sp.insert(m(v[prev_a - 1].S, a));
        }
        if (sp.find(m(b, v[next_b - 1].S)) == sp.end() && self_b != n && b < v[next_b - 1].S) {
            ans++;

            sp.insert(m(b, v[next_b - 1].S));
        }
        if (sp.find(m(v[prev_b - 1].S, b)) == sp.end() && self_b != 1 && v[prev_b - 1].S < b) {
            ans++;

            sp.insert(m(v[prev_b - 1].S, b));
        }

        swap(v[self_a - 1].S, v[self_b - 1].S);
        pos[a] = self_b;
        pos[b] = self_a;
        sp.clear();
        swap(a, b);

        if (self_a != n && a < v[next_a - 1].S) {
            ans--;
            sp.insert(m(a, v[next_a - 1].S));
        }
        if (sp.find(m(v[prev_a - 1].S, a)) == sp.end() && self_a != 1 && v[prev_a - 1].S < a) {
            ans--;

            sp.insert(m(v[prev_a - 1].S, a));
        }
        if (sp.find(m(b, v[next_b - 1].S)) == sp.end() && self_b != n && b < v[next_b - 1].S) {
            ans--;

            sp.insert(m(b, v[next_b - 1].S));
        }
        if (sp.find(m(v[prev_b - 1].S, b)) == sp.end() && self_b != 1 && v[prev_b - 1].S < b) {
            ans--;

            sp.insert(m(v[prev_b - 1].S, b));
        }

        cout << ans << endl;
    }

    return 0;
}
