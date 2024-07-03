#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VB = vector<bool>;

VE V;
int x, n;

int f(int i, int suma) {
    if (suma > x) return 0;

    if (i == n) return suma == x;

    int res = 0;
    for (int j = 0; j <= 2; ++j) {
        res += f(i + 1, suma + j*V[i]);
    }
    return res;
}

int main() {
    while (cin >> x >> n) {
        V = VE(n);
        for (int& x : V) cin >> x;
        cout << f(0,0) << endl;
    }
}