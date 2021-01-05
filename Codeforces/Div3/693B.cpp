#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    int _; cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int a1 = 0, a2 = 0;
        for (int i = 0; i < n; ++i) {
            int t; cin >> t;
            if (t == 1) a1++;
            else a2++;
        }
        if (a1 % 2) {
            cout << "NO\n";
            continue;
        }
        a2 *= 2;
        if (a1 < a2) {
            int bol = a1;
            while (a1 < a2) {
                a1 +=2;
                a2 -= 2;
            }
            if (a1 - a2 == 2) {
                if (bol > 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
                continue;
            }
            if (a1 == a2) {
                cout << "YES\n";
            }
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}