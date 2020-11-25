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
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string t;
        cin >> t;
        auto z1 = zet(s + t), z2 = zet(t + s);
        int a1 = -1;
        int in1 = 0, in2 = 0;
        for (int i = s.size(); i < z1.size(); ++i) {
            if (z1[i] >= s.size()) {
                in1 = 1;
                break;
            }
            if (a1 == -1 && i + z1[i] == z1.size()) {
                a1 = z1[i];
            }
        }
        int a2 = -1;
        for (int i = t.size(); i < z2.size(); ++i) {
            if (z2[i] >= t.size()) {
                in2 = 1;
                break;
            }
            if (a2 == -1 && i + z2[i] == z2.size()) {
                a2 = z2[i];
            }
        }
        if (in1) {
            cout << t << endl;
            continue;
        } else if (in2) {
            cout << s << endl;
            continue;
        } else if (a1 < 0 && a2 < 0) {
            cout << t + s << endl;
            continue;
        }
        if (a2 < a1) { // собачим вторую к первой
            swap(a1, a2);
            swap(t, s);
        }
        for (int i = 0; i < s.size() - a2; ++i) {
            cout << s[i];
        }
        for (int i = 0; i < t.size(); ++i) {
            cout << t[i];
        }
        cout << endl;
    }
    return 0;
}