#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

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
    string ss = s + s;
    auto z = zet(ss);
    int k = 1;
    for (int i = 1; i < s.size() ;i++) {
        if (z[i] < s.size() && ss[0 + z[i]] > ss[i + z[i]]) {
            k++;
        }
    }
    cout << k << endl;
    return 0;
}

//7 10
//1 2 3 4 5 6 6