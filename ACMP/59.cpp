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
    int n, k;
    cin >> n >> k;
    int pr = 1, sm = 0;
    while (n) {
        pr *= (n % k);
        sm += (n % k);
        n /= k;
    }

    cout << pr - sm;

    return 0;
}