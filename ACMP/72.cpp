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
//    for (char c : s) {
//        cout << (int)c << ' ';
//    }
    int a = -1;
    for (int i = s.size() - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            a = i;
            break;
        }
    }
    int b = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] > s[a]) {
            b = i;
            break;
        }
    }
    swap(s[a], s[b]);
    if (a < b)
        reverse(s.begin() + a + 1, s.end());
//    while (a < b) {
//        swap(s[a], s[b]);
//        a++; b--;
//    }
    cout << s;
    return 0;
}