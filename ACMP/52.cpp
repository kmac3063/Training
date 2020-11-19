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

int sum(int n) {
    int ans = 0;
    while (n) {
        ans += n%10;
        n/=10;
    }
    return ans;
}
int main() {
    int n; cin >> n;
    if (sum(n % 1000) == sum(n / 1000)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}