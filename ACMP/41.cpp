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
    int A[201];
    for (int i = 0; i < 201; ++i) {
        A[i] = 0;
    }
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        A[t + 100]++;
    }
    for (int i = 0; i < 201; ++i) {
        for (int j = 0; j < A[i]; ++j) {
            cout << i - 100 << ' ';
        }
    }
    return 0;
}