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
    int n, k; cin >> n >> k;
    vector<int> A, B, AB;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a == 1 && b == 1) {
            AB.push_back(t);
        } else if (a == 1) {
            A.push_back(t);
        } else if (b == 1) {
            B.push_back(t);
        }
    }
    int a = 0, b = 0;
    int ans = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(AB.begin(), AB.end());
    for (int i = 0; i < k; ++i) {
        int t1 = 1e9, t2 = 1e9;
        if (a < min(A.size(), B.size())) {
            t1 = A[a] + B[a];
        }
        if (b < AB.size()) {
            t2 = AB[b];
        }

        if (t1 == 1e9 && t2 == 1e9) {
            cout << -1;
            return 0;
        }
        if (t1 < t2) {
            a++;
            ans += t1;
        } else {
            b++;
            ans += t2;
        }
    }
    cout << ans;

    return 0;
}