#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<ll> v(n);
        vector<ll> odd, even;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] % 2) {
                odd.push_back(v[i]);
            } else {
                even.push_back(v[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        int p1 = 0, p2 = 0;
        int b = 0;
        ll alice = 0, bob = 0;
        while (p1 != odd.size() && p2 != even.size()) {
            if (b == 0){ // алиса четное
                if (odd[p1] > even[p2]) {
                    p1++;
                } else {
                    alice += even[p2];
                    p2++;
                }
                b^=1;
            } else {
                if (odd[p1] > even[p2]) {
                    bob += odd[p1];
                    p1++;
                } else {
                    p2++;
                }
                b^=1;
            }
        }
        while (p1 != odd.size()) {
            if (b == 1) {
                bob += odd[p1];
            }
            p1++;
            b ^=1;
        }

        while (p2 != even.size()) {
            if (b == 0) {
                alice += even[p2];
            }
            p2++;
            b ^=1;
        }

        if (alice > bob) {
            cout << "Alice";
        } else if (alice < bob) {
            cout << "Bob";
        } else {
            cout <<"Tie";
        }
        cout << endl;
    }
    return 0;
}