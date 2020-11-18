#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

struct Tm {
    int h, m, s;
};

int A[10];

void count(Tm& a) {
    A[a.h / 10]++;
    A[a.h % 10]++;
    A[a.m / 10]++;
    A[a.m % 10]++;
    A[a.s / 10]++;
    A[a.s % 10]++;
}

void plus1(Tm& a) {
    if (a.s != 59) {
        a.s++;
    } else {
        a.s = 0;
        if (a.m != 59) {
            a.m++;
        } else {
            a.m = 0;
            a.h++;
        }
    }
}

bool eq(Tm a, Tm b) {
    return a.s == b.s && a.m == b.m && a.h == b.h;
}

int main() {
    for (int i = 0; i < 10;i++)
        A[i] = 0;
    char c;
    Tm a, b;
    cin >> a.h >> c >> a.m >> c >> a.s;
    cin >> b.h >> c >> b.m >> c >> b.s;
    count(a);
    while (!eq(a, b)) {
        plus1(a);
        count(a);
    }
    for (int i = 0; i < 10; ++i) {
        cout << A[i] << endl;
    }
}