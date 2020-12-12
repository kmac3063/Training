#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
#include <map>

#define ll long long

using namespace std;
int n;
bool f(vector<int> need, vector<pair<int, int>>& sale1, int lastDay) {
    vector<int> sale(need.size(), -1);
    for (int i = 0; i < sale1.size(); ++i) {
        if (sale1[i].first <= lastDay)
        sale[sale1[i].second] = max(sale[sale1[i].second], sale1[i].first);
    }

    map<int, vector<int>> saleM;
    for (int i = 0; i < need.size(); ++i) {
        if (sale[i] != -1)
            saleM[sale[i]].push_back(i);
    }

    int money = 0;
    for (int i = 0; i <= lastDay; ++i) {
        money++;
        for (auto s : saleM[i]) {
            int n1 = need[s];
            if (n1 <= money) {
                need[s] = 0;
                money -= n1;
            } else {
                need[s] -= money;
                money = 0;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < need.size(); ++i) {
        ans += need[i] * 2;
    }

    return money >= ans;
}

int main() {
    int m; cin >> n >> m;
    vector<int> need(n);
    for (int i = 0; i < n; ++i) {
        cin >> need[i];
    }

    vector<pair<int, int>> sale(m);

    for (int i = 0; i < m; ++i) {
        cin >> sale[i].first >> sale[i].second;
        sale[i].first--; sale[i].second--;
    }

    int l = 0, r = 1e6;
    while (l + 1 < r) {
        int m1 = (l + r) / 2;
        if (f(need, sale, m1)) {
            r = m1;
        } else {
            l = m1;
        }
    }
    for (int a = l - 1; a <= r + 1; a++) {
        if (f(need, sale, a)) {
            cout << a + 1<< endl;
            return 0;
        }
    }
    cout << r + 1<< endl;
    return 0;
}


















