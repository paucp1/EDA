#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void recorregut(vector<char>& sol, int i, int idx) {
    int n = sol.size();
    if (idx == n) escriu(sol);
    else {
        if (i > 0) {
            sol[idx] = 'd';
            recorregut(sol, i-1, idx+1);
        }

        sol[idx] = 'h';
        recorregut(sol, i, idx+1);

        sol[idx] = 'u';
        recorregut(sol, i+1, idx+1);
    }
}

int main () {
    int n;
    cin >> n;
    vector<char> sol(n);
    int i = 0;
    recorregut(sol, i, 0);
}