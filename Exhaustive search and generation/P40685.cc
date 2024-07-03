#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VB = vector<bool>;

int s, n;
VE V;
VB triat;

void escriu() {
    cout << '{';
    bool primer = true;
    for (int i = 0; i < n; ++i) {
        if (triat[i]){
            if (primer) primer = false;
            else cout << ',';
            cout << V[i];
        }
    }
    cout << '}' << endl;
}

void f(int i, int suma) {
    if (i == n) {
        if (suma == s) escriu();
        return;
    }

    triat[i] = false;
    f(i + 1, suma);
    triat[i] = true;
    f(i + 1, suma + V[i]);
}

int main() {
    cin >> s >> n;
    V = VE(n);
    triat = VB(n, false);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        V[i] = x;
    }
    f(0, 0);
}