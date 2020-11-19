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
        n /= 10;
    }
    return ans;
}
int main() {
    int n; cin >> n;
    int n1 = n;
    vector<int> v;
    for (int i = 1; i * i <= n1; i++) {
        if (n1 % i == 0) {
            v.push_back(i);
            if (i * i != n) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end(), [](int a, int b) -> auto {
        if (sum(a) > sum(b)) {
            return true;
        } else if (sum(a) == sum(b)) {
            return a < b;
        }
        return false;
    });
    cout << v[0];
    return 0;
}