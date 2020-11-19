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

vector<int> f(int n) {
    if (n < 10) {
        return {n};
    }
    map<int, int> m;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0 && i > 9) {
            return {-1};
        }
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n > 9) {
        return {-1};
    }
    if (n != 1) {
        m[n]++;
    }

    while (m[3] >= 2) {
        m[3] -= 2;
        m[9]++;
    }
    while (m[2] >= 3) {
        m[2] -= 3;
        m[8]++;
    }

    if (m[2] && m[3]) {
        m[6]++;
        m[3]--;
        m[2]--;
    }
    if (m[2] == 2) {
        m[2] = 0;
        m[4]++;
    }

    vector<int> ans;
    for (int i = 2; i < 10; ++i) {
        while (m[i]) {
            ans.push_back(i);
            m[i]--;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 10;
        return 0;
    }
    auto v = f(n);
    for (auto& i : v) {
        cout << i;
    }
    return 0;
}