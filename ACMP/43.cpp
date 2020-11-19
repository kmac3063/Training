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
    int ans = 0;
    int anst = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            anst++;
            ans = max(ans, anst);
        } else {
            anst = 0;
        }
    }
    cout << ans;
    return 0;
}