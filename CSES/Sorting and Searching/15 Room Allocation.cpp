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
    multiset<pii> ends;
    vector<pair<int, pii>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F >> v[i].S.F;
        v[i].S.S = i;
    }
    sort(all(v));
    int mx = -1;
    set<int> free_room;
    int k = 1;
    vi ans(n);
    for (auto& p: v) {
        // TODO Нужно добавить сохранение комнаты вместе с концом
        auto it = ends.lower_bound({p.F, 0});
        auto it1 = ends.begin();
        vector<pii> v1;
        while (it1 != it) {
            v1.pb(*it1);
            it1++;
        }

        for (auto i : v1) {
            free_room.insert(i.S);
            ends.erase(i);
        }

//        add_new_end;
        if (free_room.empty()) {
            free_room.insert(k++);
        }
        ends.insert({p.S.F, *free_room.begin()});

        ans[p.S.S] = *free_room.begin();
        free_room.erase(free_room.begin());

    }
    cout << k - 1 << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}
