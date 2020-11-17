#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    auto v = vector<string>({s1, s2, s3});
    int sz1 = s1.size();
    if (s2.size() != sz1 || s3.size() != sz1) {
        sort(v.begin(), v.end(), [](auto a, auto b) -> auto {return a.size() > b.size();});
        if (v[0].size() == v[1].size()) {
            cout << max(v[0], v[1]);
        } else
            cout << v[0];
    } else {
        cout << max(v[0], max(v[1], v[2]));
    }

    return 0;
}
