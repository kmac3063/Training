#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

int get(string s, int i, char ch) {
    s[i] = ch;
    int ans = 0;
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] > s[i]) {
            ans += abs(j - i);
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        string ans(n, 'a' - 1);
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        int k = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> tv;
            for (int j = 0; j < n; ++j) {
                if (v[j] == 0 && ans[j] == 'a' - 1) {
                    tv.push_back(j);
                }
            }

            auto temp = v;
            if (tv.size() == 0) continue;
            while (count(s.begin(), s.end(), s[k]) < tv.size()) {
                k++;
            }
            for (int j = 0; j < n; ++j) {
                if (temp[j] == 0 && ans[j] == 'a' - 1) {
                    ans[j] = s[k];
                    continue;
                }

                for (auto x : tv) {
                    v[j] -= abs(x - j);
                }
            }
            k++;
            while (k < s.size() && s[k] == s[k - 1]) k++;
        }

        cout << ans << endl;
    }
    return 0;
}


















