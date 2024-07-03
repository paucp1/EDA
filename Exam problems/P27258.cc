#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tauler;

bool monstre(Tauler& t, int i, int j, int f, int c) {
    if (i-1 >= 0 and t[i-1][j] == 'M') return true;
    if (i+1 < f and t[i+1][j] == 'M') return true;
    if (j-1 >= 0 and t[i][j-1] == 'M') return true;
    if (j+1 < c and t[i][j+1] == 'M') return true;
    return false;
}

bool dfs(Tauler& t, int i, int j) {
    int f = t.size();
    int c = t[0].size();
    if (i < 0 or i >= f or j < 0 or j >= c) return false;
    if (monstre(t, i, j, f, c)) return false;
    if (t[i][j] == 'X') return false;
    if (t[i][j] == 'F') return true;
    t[i][j] = 'X';
    return dfs(t, i-1, j) or dfs(t, i, j-1) or dfs(t, i, j+1) or dfs(t, i+1, j);
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Tauler t(n, vector<char>(m));
        int ini_i, ini_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                t[i][j] = c;
                if (c == 'I') {
                    ini_i = i;
                    ini_j = j;
                }
            }
        }
        cout << (dfs(t, ini_i, ini_j) ? "SI" : "NO") << endl;
    }
}