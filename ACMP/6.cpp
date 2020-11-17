#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool n(char c) {
    return !('A' <= c && c <= 'H');
}

bool n1(char c) {
    return !('1' <= c && c <= '8');
}

int main() {
    string s; cin >> s;
    if (s.size() != 5 || s[2] != '-' || n(s[0]) || n(s[3]) || n1(s[1]) || n1(s[4])) {
        cout << "ERROR";
    } else {
        int d1 = abs(s[0] - s[3]);
        int d2 = abs(s[1] - s[4]);
        if (d1 == 1 && d2 == 2 || d1 == 2 && d2 == 1) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
}
