#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t % 2) {
            v1.push_back(t);
        } else {
            v2.push_back(t);
        }
    }
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << ' ';
    }
    cout << endl;
    if (v1.size() > v2.size()) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}
