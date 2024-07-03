#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void paraules(vector<char>& sol, vector<char>& alfabet, vector<bool>& usada, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        for (int i = 0; i < alfabet.size(); ++i) {
            if (not usada[i]) {
                if (idx == 0 or sol[idx-1] != alfabet[i]-1) {
                    sol[idx] = alfabet[i];
                    usada[i] = true;
                    paraules(sol, alfabet, usada, idx+1);
                    usada[i] = false;
                }
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<char> sol(n);
    vector<char> alfabet(n);
    vector<bool> usada(n, false);
    for (int i = 0; i < n; ++i) {
        alfabet[i] = 'a' + i;
    }
    paraules(sol, alfabet, usada, 0);
}