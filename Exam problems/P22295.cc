#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> T;
typedef vector<vector<bool>> B;

void escriu(const vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
}

bool posicio_valida(T& t, int i, int j) {
    int n = t.size();
    int m = t[0].size();
    if (i >= 0 and i < n and j >= 0 and j < m) return true;
    return false;
}

void trobar_camins(T& t, vector<char>& sol, B& b, int i, int j, int i_fi, int j_fi) {
    if (i == i_fi and j == j_fi) {
        escriu(sol);
        cout << t[i][j] << endl;
    }
    else {
        if (posicio_valida(t, i, j) and not b[i][j]) {
            sol.push_back(t[i][j]);
            b[i][j] = true;
            trobar_camins(t, sol, b, i-1, j, i_fi, j_fi);
            trobar_camins(t, sol, b, i, j-1, i_fi, j_fi);
            trobar_camins(t, sol, b, i, j+1, i_fi, j_fi);
            trobar_camins(t, sol, b, i+1, j, i_fi, j_fi);
            sol.pop_back();
            b[i][j] = false;
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    T t(n, vector<char>(m));
    B b(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }
    int i, j, i_fi, j_fi;
    cin >> i >> j;
    cin >> i_fi >> j_fi;
    vector<char> sol;
    trobar_camins(t, sol, b, i, j, i_fi, j_fi);
}