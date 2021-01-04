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
        int n;
        cin >> n;
        string s; cin >> s;
        vector<int> ans(n);

        vector<int> zero, one;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - '0';
            if (ch == 0) {
                if (one.size() != 0) {
                    ans[i] = ans[one.back()];
                    one.erase(prev(one.end()));
                } else {
                    ans[i] = ++k;
                }
                zero.push_back(i);
            } else {
                if (zero.size() != 0) {
                    ans[i] = ans[zero.back()];
                    zero.erase(prev(zero.end()));
                } else {
                    ans[i] = ++k;
                }
                one.push_back(i);
            }
        }
        cout << k << endl;
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}