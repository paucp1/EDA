#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void paraules(vector<char>& sol, int n_a, int n_b, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        if (n_a < n_b + 2) {
            ++n_a;
            sol[idx] = 'a';
            paraules(sol, n_a, n_b, idx+1);
            --n_a;
        }

        if (n_b < n_a + 2) {
            ++n_b;
            sol[idx] = 'b';
            paraules(sol, n_a, n_b, idx+1);
            --n_b;
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<char> sol(n);
    int n_a = 0;
    int n_b = 0;
    paraules(sol, n_a, n_b, 0);
} 