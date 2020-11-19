

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

int main() {
    string s;
    cin >> s;
    string ans = "1";
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            ans.push_back('0');
        } else {
            break;
        }
    }
    cout << ans;
    return 0;
}