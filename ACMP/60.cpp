#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector<int> erat(int n) {
    vector<int> ans;
    vector<char> er(n + 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            er[j] = 1;
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        if (er[i] == 0)
            ans.push_back(i);
    }
    return ans;
}

int main() {
    int k; cin >> k;
    auto v = erat(1e5);
    cout << v[v[k]];
    return 0;
}