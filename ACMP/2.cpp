#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0)
        cout << (1 + n) * n / 2;
    else {
        n = -n;
        cout << -(1 + n) * n / 2 + 1;
    }
    return 0;
}
