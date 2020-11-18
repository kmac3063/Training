#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int n = a + b - 1;
    cout << n - a << ' ' << n - b;
}
