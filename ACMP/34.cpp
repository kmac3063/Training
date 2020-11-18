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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string_view, int> m;
    for (int i = 0; i < n - k + 1; ++i) {
        string_view sv(s);
        sv.remove_prefix(i);
        sv.remove_suffix(n - (i + k));
        if (++m[sv] == 2) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
