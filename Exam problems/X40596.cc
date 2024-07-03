#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void escriu(vector<int>& sol) {
    cout << "(";
    for (int i = 0; i < sol.size(); ++i) {
        if (i != 0) cout << ",";
        cout << sol[i];
    }
    cout << ")" << endl;
}

bool compatible(int i, int j, int d) {
    return abs(i-j) <= d;
}

void sequencia(vector<int>& sol, vector<bool>& usat, int d, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        for (int i = 1; i <= n; ++i) {
            if (not usat[i-1]) {
                if (idx == 0 or compatible(sol[idx-1], i, d)) {
                    usat[i-1] = true;
                    sol[idx] = i;
                    sequencia(sol, usat, d, idx+1);
                    usat[i-1] = false;
                }
            }
        }
    }
}

int main () {
    int n, d;
    cin >> n >> d;
    vector<int> sol(n);
    vector<bool> usat(n, false);
    sequencia(sol, usat, d, 0);
}