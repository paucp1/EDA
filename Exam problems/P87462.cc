#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tauler;

bool perill(Tauler& t, int i, int j) {
    int f = t.size();
    int c = t[0].size();
    if (i-1 >= 0 and j-1 >= 0 and t[i-1][j-1] == 'F') return true;
    if (i-1 >= 0 and t[i-1][j] == 'F') return true;
    if (i-1 >= 0 and j+1 < c and t[i-1][j+1] == 'F') return true;

    if (i+1 < f and j-1 >= 0 and t[i+1][j-1] == 'F') return true;
    if (i+1 < f and t[i+1][j] == 'F') return true;
    if (i+1 < f and j+1 < c and t[i+1][j+1] == 'F') return true;

    if (j-1 >= 0 and t[i][j-1] == 'F') return true;
    if (j+1 < c and t[i][j+1] == 'F') return true;
    return false;
}

bool dfs(Tauler& t, int i, int j) {
    int f = t.size();
    int c = t[0].size();
    if (i < 0 or i >= f or j < 0 or j >= c) return false;
    if (t[i][j] == 'X') return false;
    if (perill(t, i, j)) return false;
    if (t[i][j] == 'B') return true;
    t[i][j] = 'X';
    return dfs(t, i-1, j) or dfs(t, i, j-1) or dfs(t, i, j+1) or dfs(t, i+1, j);
}


int main () {
    int f, c;
    while (cin >> f >> c) {
        Tauler t(f, vector<char>(c));
        int pi, pj;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                char x;
                cin >> x;
                t[i][j] = x;
                if (x == 'P') {
                    pi = i;
                    pj = j;
                }
            }
        }
        cout << (dfs(t, pi, pj) ? "si" : "no") << endl;
    }
}