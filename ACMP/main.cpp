#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector<int> zet(vector<int>& v) {
    vector<int> z(v.size());
    z[0] = 0;
    int l = -1, r = -1;
    for (int i = 1; i < v.size(); ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < v.size() && v[z[i]] == v[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    auto z = zet(v);
    for (int i = 0; i < z.size(); ++i) {
        if (i + z[i] == z.size() && (v.size() - 1) % i == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << z.size() << endl;
}

