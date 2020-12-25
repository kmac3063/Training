#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;
        int d = n - n % x + y;
        if (d > n) {
            d -= x;
        }
        cout << d << endl;
    }
    return 0;
}


















