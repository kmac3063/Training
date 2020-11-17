#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool f(ll a, ll b, ll c, ll d, ll x) {
    return (a * x * x * x + b * x * x + c * x + d == 0);
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = -100; i <= 100; ++i) {
        if (f(a, b, c, d, i)) {
            cout << i << ' ';
        }
    }
    return 0;
}
