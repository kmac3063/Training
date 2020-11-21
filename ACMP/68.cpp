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
    string s;
    int n;
    cin >> s >> n;
    if (n % 2 || s[0] == 'H' && n % 2 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}