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
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int m = n - 2;
        while (m >= 0 && v[m] >= v[m + 1])
            m--;
        while (m >= 0 && v[m] <= v[m + 1])
            m--;

        cout << m + 1 << endl;
    }

    return 0;
}