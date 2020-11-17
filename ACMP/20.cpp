#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int n, cur;
    scanf("%d %d", &n, &cur);
    int prev = cur, prevprev = cur;

    int len = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        prevprev = prev;
        prev = cur;
        scanf("%d", &cur);
        if ((prevprev < prev && prev > cur) || (prevprev > prev && prev < cur)) {
            len ++;
        } else if (prev != cur) {
            len = 2;
        } else {
            len = 1;
        }
        ans = max(ans, len);
    }

    cout << ans;
}

