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

ll len(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    int n; cin >> n;
    string qs; cin >> qs;
    while (qs.size() != 5) {
        qs.push_back('0');
    }
    int q = stoi(qs.substr(2, 3));
    int ax, ay, bx, by;
    for (int i = 0; i < n; ++i) {
        cin >> ax >> ay >> bx >> by;
        if (len(ax, ay, 0, 0) * q * q >= len(bx, by, 0, 0) * 1000000) {
        } else {
            cout << "No";
            return 0;
        }

    }
    cout << "Yes";
    return 0;
}
