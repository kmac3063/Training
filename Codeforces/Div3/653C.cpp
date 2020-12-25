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
        int n;
        cin >> n;
        string s; cin >> s;
        int ans = 0, a = 0;
        for (auto ch : s) {
            if (ch == '(') a++;
            else {
                a--;
                if (a < 0) {
                    ans++;
                    a = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}