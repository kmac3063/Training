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
    if (a < b) {
        cout << '<';
    } else if (a > b){
        cout << '>';
    } else {
        cout << '=';
    }
}

