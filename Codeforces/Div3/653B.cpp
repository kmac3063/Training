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
        int n; cin >> n;
        int a = 0;
        int k = n;
        while (k % 2 == 0) {
            a++; k/=2;
        }
        int b = 0;
        while (k % 3 == 0) {
            b++; k/= 3;
        }
        if (k == 1 && a <= b) {
            cout << (b - a) + b << endl;
        } else {
            cout << -1 << endl;
        }

    }
    return 0;
}