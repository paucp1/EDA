#include <iostream>
#include <vector>
using namespace std;

void omplir_lletres(vector<char>& ll) {
    ll[0] = 'A';
    ll[1] = 'C';
    ll[2] = 'G';
    ll[3] = 'T';
}

void escriu(vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void adn(vector<char>& sol, vector<char>& ll, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        for (int i = 0; i < ll.size(); ++i) {
            sol[idx] = ll[i];
            adn(sol, ll, idx+1);
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<char> ll(4);
    vector<char> sol(n);
    omplir_lletres(ll);
    adn(sol, ll, 0);
}