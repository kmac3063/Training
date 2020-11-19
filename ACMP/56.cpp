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
    int n; cin >> n;
    set<string> s1;
    for (int i = 0; i < n; ++i) {
        string ts;
        cin >> ts;
        s1.insert(ts);
    }
    int m; cin >> m;
    set<string> s2;
    for (int i = 0; i < m; ++i) {
        string ts;
        cin >> ts;
        s2.insert(ts);
    }
    cout << "Friends: ";
    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << *it;
        if (next(it) != s1.end()) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Mutual Friends: ";
    vector<string> v1;
    for (auto it = s1.begin(); it != s1.end(); it++) {
        if (s2.find(*it) != s2.end())
            v1.push_back(*it);
    }
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i];
        if (i != v1.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Also Friend of: ";
    vector<string> v2;
    for (auto it = s2.begin(); it != s2.end(); it++) {
        if (s1.find(*it) == s1.end()) {
            v2.push_back(*it);
        }
    }
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i];
        if (i != v2.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}