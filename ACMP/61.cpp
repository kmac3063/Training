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
    int a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        a += t1; b += t2;
    }
    if (a > b) {
        cout << 1;
    } else if (a == b) {
        cout << "DRAW";
    } else {
        cout << 2;
    }
    return 0;
}