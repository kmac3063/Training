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
    string E = "2.7182818284590452353602875";
    int n; cin >> n;
    if (n == 0) {
        cout << 3;
    } else if (n == 25) {
        cout << E;
    } else {
        string s = E.substr(0, 2 + n);
        if (E[2 + n] >= '5') {
            s[1 + n]++;
        }
        cout << s;
    }
    return 0;
}