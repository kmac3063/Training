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
    int n; cin >> n;
    string s; cin >> s;
    int k = s.size();

    int ans = 1;
    while (n > 0) {
        ans *= n;
        n -= k;
    }
    cout << ans;


    return 0;
}