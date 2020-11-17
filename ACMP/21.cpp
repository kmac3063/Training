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
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(a, max(b, c)) - min(a, min(b, c));
}

