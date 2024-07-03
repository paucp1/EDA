#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VE;
typedef vector<bool> VB;

VE canvi;
VB c1, c2;

void escriu(int x, int n) {
    int sum = 0;
    cout << x << " = ";
    for (int i = 0; i < n; ++i) {
        if (c1[i]) {
            cout << canvi[i];
            sum += canvi[i];
            if (sum != x) cout << " + ";
        }
        if (c2[i]) {
            cout << canvi[i] << "p";
            sum += canvi[i];
            if (sum != x) cout << " + ";
        }
    }
    cout << endl;
}

void tornar_canvi(int x, int n, int suma, int idx) {
    if (suma == x) escriu(x, n);
    else if (suma < x and idx < n) {
        if (suma+canvi[idx] <= x) {
            if (!c1[idx]) {
                c1[idx] = true;
                tornar_canvi(x, n, suma+canvi[idx], idx);
                c1[idx] = false;
            }

            if (!c2[idx]) {
                c2[idx] = true;
                tornar_canvi(x, n, suma+canvi[idx], idx+1);
                c2[idx] = false;
            }

            tornar_canvi(x, n, suma, idx+1);
        }
    }
}

void backtracking(int x, int n){
    sort(canvi.begin(), canvi.end());
    c1 = c2 = VB(n, false);
    tornar_canvi(x, n, 0, 0);
    cout << "----------" << endl;
}

int main () {
    int x, n;
    while (cin >> x >> n) {
        canvi = VE(n);
        for (int i = 0; i < n; ++i) {
            cin >> canvi[i];
        }
        backtracking(x, n);
    }
} 