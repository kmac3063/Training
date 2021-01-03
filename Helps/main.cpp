#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    int n, k; cin >> n >> k;
    vector<int> F(201);
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 200; ++i) {
        F[i] = F[i - 2] + F[i - 1]
    }
    return 0;
}
