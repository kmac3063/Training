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
        string s; cin >> s;
        string ans = "";
        ans.push_back(s[0]);
        for (int i = 1; i < s.size() - 1; i += 2) {
            ans += s[i];
        }
        ans.push_back(s.back());
        cout << ans << endl;
    }
    return 0;
}


















