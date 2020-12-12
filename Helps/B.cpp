#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = (i ? pref[i - 1] : 0) + v[i];
    }
    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << pref[r] - (l ? pref[l - 1] : 0) << endl;
    }
    return 0;
}
