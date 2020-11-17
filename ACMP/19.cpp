#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string s = s1 + ' ' + s2 +' '+ s3;
    int x1, x2, x3;
    int ans = 0;
    int y1, y2, y3;
    x1 = s[0] - 'A', x2 = s[3] - 'A', x3 = s[6] - 'A';
    y1 = s[1] - '1', y2 = s[4] - '1', y3 = s[7] - '1';
    vector<vector<bool>> v(8, vector<bool>(8, 0));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == x1 && j == y1 || i == x2 && j == y2 || i == x3 && j == y3) {
                continue;
            }
            if (i == x1 || j == y1 || abs(i - x1) == abs(j - y1) ||
                i == x2 || j == y2 ||
                abs(i - x3) * abs(j - y3) == 2) {
                ans++;
            }
        }
    }
    cout << ans;
}

