#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

struct rect {
    int x1, y1, x2, y2;
};

int main() {
    int w, h;
    cin >> w >> h;
    int n; cin >> n;
    vector<rect> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
        v[i].x2--;
        v[i].y2--;
    }
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            bool b = 0;
            for (int k = 0; k < v.size(); ++k) {
                if (v[k].x1 <= i && i <= v[k].x2 &&
                v[k].y1 <= j && j <= v[k].y2) {
                    b = 1;
                    break;
                }
            }
            if (b == 0) {
                ans ++;
            }
        }
    }
    cout << ans;
}

