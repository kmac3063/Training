#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define ll long long

using namespace std;

struct T {
    T(){};
    T(int len_, int l_, int r_) : len(len_), l(l_), r(r_) {};
    int len;
    int l;
    int r;

    bool operator<(const T& b) const {
        if (len == b.len)
            return l < b.l;
        else
            return len > b.len;
    }
};



int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        //        if (n % 2) {
        //            vector<int> ans(n);
        //            int m = (1 + n) / 2 - 1;
        //            ans[m] = 1;
        //            for (int i = 0; i < m; ++i) {
        //                ans[i] = (i + 1) * 2;
        //            }
        //            for (int i = m + 1; i < ans.size(); ++i) {
        //                ans[i] = (i - m - 1) * 2 + 3;
        //            }
        //            for (int i = 0; i < n; ++i) {
        //                cout << ans[i] <<  ' ';
        //            }
        //            cout << endl;
        //        } else {
        //            3 4 6 1 7 2 5 8
        //        }
        set<T> q;
        q.insert(T(n ,1, n));
        int i = 1;
        vector<int> ans(n);
        while (q.empty() == 0) {
            T t = *q.begin();
            q.erase(q.begin());
            if (t.l > t.r) continue;
            int m = (t.l + t.r) / 2;
            ans[m - 1] = i++;
            q.insert(T(m - t.l, t.l, m - 1));
            q.insert(T(t.r - m, m + 1, t.r));
        }
        for (int j = 0; j < n; ++j) {
            cout << ans[j] << ' ';
        }
        cout << endl;
    }
    //    *****
    //    *****
    //    *****
    //    *****
    //    *****
    return 0;
}
