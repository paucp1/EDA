#include <iostream>
#include <vector>
#include <string>
using namespace std;

void escriu(vector<string>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

bool compatible(string& s1, string& s2) {
    int i = s1.size()-1;
    return s1[i] != s2[0];
}

void concatenacio(vector<string>& sol, vector<string>& par, vector<bool>& usada, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        for (int i = 0; i < n; ++i) {
            if (not usada[i]) {
                if (idx == 0 or compatible(sol[idx-1], par[i])) {
                    usada[i] = true;
                    sol[idx] = par[i];
                    concatenacio(sol, par, usada, idx+1);
                    usada[i] = false;
                }
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<string> sol(n);
    vector<string> par(n);
    vector<bool> usada(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> par[i];
    }
    concatenacio(sol, par, usada, 0);
}