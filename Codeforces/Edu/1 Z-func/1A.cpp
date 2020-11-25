#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int z(string& s) {
    int n = s.size();
    s.resize(n + 1 + n);
    s[n] = '#';
    for (int i = 0; i < n; ++i) {
        s[n + i + 1] = s[n - i - 1];
    }

//    s += '#';
//    string sTemp = s;
//    reverse(sTemp.begin(), sTemp.end());
//    s += sTemp;

    vector<int> z(s.size());
    z[0] = 0;
    int l, r = -1;
    int i = 1;
    while (i != s.size()) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i < s.size() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (i + z[i] == s.size()) {
            return z[i];
        }

        i++;
    }

    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << z(s) << endl;
    }
    return 0;
}