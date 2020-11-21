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
    string s; cin >> s;
    int k; cin >> k;
    string ans = "";
    if (k > 0) {
        while (k && ans.size() < 1023) {
            ans += s;
            k--;
        }
        for (int i = 0; i < min(1023, (int)ans.size()); ++i) {
            cout << ans[i];
        }
    } else {
        k = -k;
        if (s.size() % k != 0) {
            cout << "NO SOLUTION";
        } else {
            string search = s.substr(0, s.size() / k);
            bool b = 1;
            for (int i = 0; i < s.size(); i -= -1) {
                if (s[i] != search[i % search.size()]) {
                    b = 0;
                    break;
                }
            }
            if (b) {
                cout << search;
            } else {
                cout << "NO SOLUTION";
            }
        }
    }
    return 0;
}