#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define ll long long

using namespace std;

vector<int> zet(string& s) {
    vector<int> z(s.size());
    z[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (s[z[i]] == s[i + z[i]])
            z[i]++;
    }
    return z;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, j;
        cin>> k >> j;
        int n = (1 << k) - 1;
        if (j % 2 || j == 0) {
            cout << 0 << endl;
            continue;
        }

        while (j & (j - 1)) {
            if (j > n / 2) {
                j -= n / 2 + 1;
            }

            n /= 2;
        }

        cout << j - 1 << endl;
    }
    return 0;
}
