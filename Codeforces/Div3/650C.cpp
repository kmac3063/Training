#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

void pr(vector<int>& next) {
    cout << "next: ";
    for (int i = 0; i < next.size(); ++i) {
        cout << next[i] << ' ';
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if (count(s.begin(), s.end(), '1') == 0) {
            k++;
            cout << (n + k - 1) / k << endl;
            continue;;
        }
        vector<int> next;
        int len = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') len++;
            else {
                if (next.empty()) {
                    next.push_back(INT32_MAX);

                }
                else next.push_back(len);
                len = 0;
            }
        }
//        if (len)
            next.push_back(len);
        reverse(next.begin(), next.end());
        //pr(next);

        int ans = 0;
        int m = 0;
        int clear = k + 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                clear++;
                next[m]--;
            } else {
                clear = 0;
                m++;
            }

            if (clear > k && next[m] >= k) {
                ans++;
                clear = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


















