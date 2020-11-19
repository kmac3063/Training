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

int main() {
    string s = "qwertyuiopasdfghjklzxcvbnm";
    char c; cin >> c;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            cout << s[(i + 1) % s.size()];
            return 0;
        }
    }
    return 0;
}