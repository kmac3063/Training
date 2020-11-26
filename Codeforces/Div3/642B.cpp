#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < k && i < b.size(); i++ ) {
            if (a[i] >= b[i]) {
                k = i;
                break;
            }
            ans += b[i];
        }
        for (int i = k; i < b.size(); i++) {
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}

//7 10
//1 2 3 4 5 6 6