#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    int n; inputfile >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        inputfile >> v[i];
    }
    if (n == 1) {
        outputfile << 1 << endl << v[0];
        return 0;
    }
    vector<vector<vector<int>>> res(n, vector<vector<int>>(n, vector<int>()));
    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            int d = v[second] - v[first];
            int next = v[second] + d;
            res[first][second].push_back(first);
            res[first][second].push_back(second);
            for (int i = second + 1; i < n; ++i) {
                if (v[i] == next) {
                    res[first][second].push_back(i);
                    next += d;
                }
            }
        }
    }

    int first, second;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((int)res[i][j].size() > ans) {
                ans = res[i][j].size();
                first = i, second = j;
            }
        }
    }

    outputfile << ans << endl;
    for (int i = 0; i < ans; ++i) {
        outputfile << res[first][second][i] + 1 << ' ';
    }
    return 0;
}
