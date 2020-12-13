#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        int odd= 0, even= 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] % 2 != i % 2) {
                if (i % 2) {
                    odd++;
                } else {
                    even++;
                }
            }
        }
        cout << (odd == even ? odd : -1) << endl;

    }
    return 0;
}


















