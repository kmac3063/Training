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

void hanoi(int n, int from, int help, int to) {
    if (n == 1) {
        cout << from << " " << to << endl;
    } else {
        hanoi(n - 1, from, to, help);
        cout << from << " " << to << endl;
        hanoi(n - 1, help, from, to);
    }
}

int main() {
    int n; cin >> n;
    pr((1<<n) - 1);
    hanoi(n, 1, 2, 3);
    return 0;
}
