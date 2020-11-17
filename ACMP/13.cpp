#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int a = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i])
            a++;
    }
    int b = 0;
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            if (i != j && s2[j] == s1[i])
                b++;
        }
    }

    cout << a << ' ' << b;
}
