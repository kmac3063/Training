#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    string s; cin >> s;
    vector<int> v(s.size());
    for (int i = 0; i < n - 1; i+= 2) {
        if (s[i] == s[i + 1]) {
            v[i]++;
            v[i + 1]++;
        }
    }

    int j = 1, i = 0;
    int k = 0;
    while (j < s.size()) {
        if (s[i] == s[j]) {
            v[j] = -1;
            j++;
        } else {
            i = j + 1;
            j = i + 1;
        }
    }

    string ans = "";
    for (int i = 0; i < n; ++i) {
        if (v[i] >= 0)
            ans.push_back(s[i]);
    }
    if (ans.size() % 2) {
        ans.resize(ans.size() - 1);
    }
    cout << s.size() - ans.size() << endl;
    cout << ans;
    return 0;
}
