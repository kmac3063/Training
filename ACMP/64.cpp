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
    for (int i = 2; i <= n; ++i) {
        if (er[i] == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

bool check(int k) {
    for (ll i = 2; i <= k / i; i++) {
        if (k % i == 0)
            return false;
    }
    return 1;
}

int main() {
    auto v = erat(1e5);
    //cout << v.size();
    string s = "0";
    for (auto& el : v) {
        s += to_string(el);
        if (s.size() > 1e4)  {
            //cout << "YEAP";
            break;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << s[k];
    }
    return 0;
}