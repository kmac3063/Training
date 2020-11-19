#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    int mx = -1e9, mn = +1e9;
    for (int i = 0; i < n; ++i) {
        int tmn = 1e9;
        for (int j = 0; j < m; ++j) {
            tmn = min(tmn, mat[i][j]);
        }
        mx = max(mx, tmn);
    }

    for (int i = 0; i < m; ++i) {
        int tmx = -1e9;
        for (int j = 0; j < n; ++j) {
            tmx = max(tmx, mat[j][i]);
        }
        mn = min(mn, tmx);
    }
    cout << mx << ' ' << mn;

    return 0;
}