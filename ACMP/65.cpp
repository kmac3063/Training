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
    //1balck 2red, 3green 4blue
    int black = 0, red = 0, green = 0, blue = 0;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            v[i][j] = 1;
            if (i * j % 2 == 0) v[i][j] = 2;
            if (i * j % 3 == 0) v[i][j] = 3;
            if (i * j % 5 == 0) v[i][j] = 4;

            if (v[i][j] == 1) black++;
            if (v[i][j] == 2) red++;
            if (v[i][j] == 3) green++;
            if (v[i][j] == 4) blue++;
        }
    }

    cout << "RED : " << red << endl;
    cout << "GREEN : " << green << endl;
    cout << "BLUE : " << blue << endl;
    cout << "BLACK : " << black << endl;
}