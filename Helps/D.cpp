#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    int n; inputfile >> n;
    int d; inputfile >> d;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        inputfile >> v[i];
    }
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = v[0], rightMax.back() = v.back();
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], v[i]);
        rightMax[n - i - 1] = max(rightMax[i + 1], v[n - i - 1]);
    }

    int ans = v.back() - v[0];
    for (int i = 0; i + d < n; ++i) {
        ans = max(ans, leftMax[i] + rightMax[i + d]);
    }
    outputfile << ans;
    return 0;
}
