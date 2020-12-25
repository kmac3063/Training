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
        int n, k;
        cin >> n >> k;
        string s; cin >> s;
        vector<int> cnt(26);
        for (auto& ch : s) {
            cnt[ch - 'a']++;
        }

        for (int len = n; len >= 1; len--) {
            vector<int> cycles;
            vector<int> used(len);
            for (int i = 0; i < len; ++i) {
                if (used[i]) continue;
                int j = i;
                cycles.push_back(0);
                while (used[j] == 0) {
                    cycles.back()++;
                    used[j] = 1;
                    j = (j + k) % len;
                }
            }
            vector<int> tmp_cnt(cnt);
            sort(tmp_cnt.begin(), tmp_cnt.end());
            sort(cycles.begin(), cycles.end());

            bool b = 1;
            while (cycles.size()) {
                if (cycles.back() > tmp_cnt.back()) {
                    b = 0;
                    break;
                }

                tmp_cnt.back() -= cycles.back();
                cycles.pop_back();
                sort(tmp_cnt.begin(), tmp_cnt.end());
            }

            if (b) {
                cout << len << endl;
                break;
            }
        }
    }
    return 0;
}


















