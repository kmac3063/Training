#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define ll long long

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    string s; cin >> s;
    string p(x, '0');
    reverse(s.begin(), s.end());
    p[y] = '1';
    int ans = 0;
    for (int i = 0; i < p.size(); ++i) {
        ans += (p[i] != s[i]);
    }
    cout << ans;
    return 0;
}
