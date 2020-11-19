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
    if ((s[0] - 'A') % 2 == (s[1] - '0') % 2) {
        cout << "WHITE";
    } else {
        cout << "BLACK";
    }
    return 0;
}