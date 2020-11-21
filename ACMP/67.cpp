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

string mas(string& s1, string& s2) {
    string s = s1;
    for (int i = 0; i < s1.size(); ++i) {
        s[i] = (s1[i] - '0') * (s2[i] - '0') + '0';
    }
    return s;
}

string to2(int a) {
    string s = "";
    while (a) {
        s.push_back(a % 2 + '0');
        a /= 2;
    }
    while (s.size() < 8) {
        s.push_back('0');
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<string> mask(n, "");
    for (int i = 0; i < n; ++i) {
        int a; char c;
        cin >> a; cin >> c;
        mask[i] += to2(a);
        cin >> a; cin >> c;
        mask[i] += to2(a);
        cin >> a; cin >> c;
        mask[i] += to2(a);
        cin >> a;
        mask[i] += to2(a);
        //cout << mask[i] << endl;
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int a; char c;
        string s;
        cin >> a; cin >> c;
        s += to2(a);
        cin >> a; cin >> c;
        s += to2(a);
        cin >> a; cin >> c;
        s += to2(a);
        cin >> a;
        s += to2(a);

        string s1;
        cin >> a; cin >> c;
        s1 += to2(a);
        cin >> a; cin >> c;
        s1 += to2(a);
        cin >> a; cin >> c;
        s1 += to2(a);
        cin >> a;
        s1 += to2(a);
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (mas(mask[j], s) == mas(mask[j], s1)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}