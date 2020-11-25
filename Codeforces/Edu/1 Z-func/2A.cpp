#include <iostream>
#include <vector>
#include <string>

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
    string s; cin >> s;
    auto z = zet(s);
    for (int i = 0; i < z.size(); ++i) {
        cout << z[i] << ' ';
    }
    return 0;
}
