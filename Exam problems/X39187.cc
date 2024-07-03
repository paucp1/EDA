#include <iostream>
#include <vector>
using namespace std;

void escriure(vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void operacions(vector<char>& sol, int monedes, int accions, int idx) {
    int n = sol.size();
    if (idx == n) escriure(sol);
    else {
        if (monedes > 0) {
            sol[idx] = 'b';
            --monedes;
            ++accions;
            operacions(sol, monedes, accions, idx+1);
            ++monedes;
            --accions;
        }

        if (accions > 0) {
            sol[idx] = 's';
            ++monedes;
            --accions;
            operacions(sol, monedes, accions, idx+1);
            --monedes;
            ++accions;
        }
    }
}

int main () {
    int n, c;
    cin >> n >> c;
    vector<char> sol(n);
    int accions = 0;
    operacions(sol, c, accions, 0);
}