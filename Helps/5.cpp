#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    double a = 0;
    double b = 0;
    inputfile >> a >> b;
    outputfile << M_PI * a * b;
    inputfile.close();
    outputfile.close();
    return 0;
}
