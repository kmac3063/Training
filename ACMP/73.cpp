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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int t = 0;
        if (s[i] <= '9') {
            t = s[i] - '0';
        } else {
            t = s[i] - 'A' + 10;
        }

        t = t - i - 1;
        while (t < 0) {
            t += 27;
        }
        t  = t + 'a' - 1;
        if ((char)t == '`') {
            t = ' ';
        }
        cout << (char)t;
    }
    return 0;
}