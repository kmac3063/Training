#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto zet(string s) {
    vector<int> z(s.size());
    int l, r = -1;
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
    return z;
}

int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (t.size() != s.size()) {
        cout << "No";
        return 0;
    }
    auto z = zet(t + s);
    int a = 0;
    for (int i = t.size(); i < z.size(); ++i) {
        if (i + z[i] == z.size()) {
            a = z[i];
            break;
        }
    }
    reverse(t.begin(), t.end());
    int d = zet(s + t)[s.size()];
    if (s.size() - a > d) {
        cout << "No" << endl;
    } else {
        cout << "Yes " << endl << s.size() - a << endl;
    }
    return 0;
}