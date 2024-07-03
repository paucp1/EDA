#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<int>& sol) {
    cout << "(";
    for (int i = 0; i < sol.size(); ++i) {
        if (i != 0) cout << ",";
        cout << sol[i];
    }
    cout << ")" << endl;
}

bool compatible(int i, int j, int k) {
    return i + k <= 2*j;
}

void pous(vector<int>& sol, vector<bool>& usat, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        for (int i = 1; i <= n; ++i) {
            if (not usat[i-1]) {
                if (idx < 2 or compatible(sol[idx-2], sol[idx-1], i)) {
                    usat[i-1] = true;
                    sol[idx] = i;
                    pous(sol, usat, idx+1);
                    usat[i-1] = false;
                }
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> sol(n);
    vector<bool> usat(n, false);
    pous(sol, usat, 0);
}