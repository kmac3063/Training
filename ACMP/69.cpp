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
    double n, a;
    cin >> n >> a;
    double R = a / (2 * sin(3.1415926535/ n));
    double r = R * cos(3.1415926535/n);
    cout << (R - r < 1 ? "YES" : "NO");
    return 0;
}