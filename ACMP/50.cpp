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

vector<int> zet(string s) {
    vector<int> z(s.size());
    int l = -1, r = -1;
    for (int i = 1; i < s.size(); i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return  z;
}

int main() {
    int ans = 0;
    string s1, s2;
    cin >> s1 >> s2;
    map<string, int> m;
    for (int i = 0; i < s2.size(); ++i) {
        string s3 = s2.substr(i, s2.size() - i) + s2.substr(0, i);
        if (m[s3]++) continue;
        //cout << s3 << endl;
        auto z = zet(s3 + s1);
        for (int j = s3.size(); j < z.size(); ++j) {
            if (z[j] >= s3.size()) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}