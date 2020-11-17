#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int mn = 1e5, mni = -1;
    int mx = -1e5, mxi = -1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] > 0)
            sum += v[i];
        if (v[i] < mn) {
            mn = v[i];
            mni = i;
        }
        if (v[i] > mx) {
            mx = v[i];
            mxi = i;
        }
    }
    int pr = 1;
    for (int i = min(mni, mxi) + 1; i <= max(mni, mxi) - 1; ++i) {
        pr *= v[i];
    }
    cout << sum << ' ' << pr;
    return 0;
}
