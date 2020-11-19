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
    int S, P;
    cin >> S >> P;
    for (int i = 1; i < 1001; ++i) {
        for (int j = 1; j < 1001; ++j) {
            if (i + j == S && i * j == P) {
                cout << min(i, j) << ' ' << max(i, j);
                return 0;
            }
        }
    }
    return 0;
}