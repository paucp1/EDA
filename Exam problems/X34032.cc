#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef vector<vector<int>> Dist;
typedef vector<pair<int, int>> Mov;

Mov mov;

void fill_mov() {
    mov[0] = make_pair(-2, -1);
    mov[1] = make_pair(-2, 1);
    mov[2] = make_pair(-1, 2);
    mov[3] = make_pair(1, 2);
    mov[4] = make_pair(2, 1);
    mov[5] = make_pair(2, -1);
    mov[6] = make_pair(1, -2);
    mov[7] = make_pair(-1, -2);
}

bool posicio_valida(Tauler& t, int i, int j) {
    int f = t.size();
    int c = t[0].size();
    if (i >= 0 and i < f and j >= 0 and j < c) return true;
    return false;
}

int bfs(Tauler& t, Dist& d, int x, int y) {
    int f = t.size();
    int c = t[0].size();
    d[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (not q.empty()) {
        pair<int, int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();
        if (t[i][j] == 'p') return d[i][j];
        for (int k = 0; k < 8; ++k) {
            int i_aux = i + mov[k].first;
            int j_aux = j + mov[k].second;
            if (posicio_valida(t, i_aux, j_aux) and t[i_aux][j_aux] != 'X') {
                if (d[i_aux][j_aux] == -1) {
                    d[i_aux][j_aux] = d[i][j] + 1;
                    q.push(make_pair(i_aux, j_aux));
                }
            }
        }
    }
    return -1;
}

int main () {
    int f, c;
    mov = Mov(8);
    fill_mov();
    while (cin >> f >> c) {
        Tauler t(f, vector<char>(c));
        Dist d(f, vector<int>(c, -1));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> t[i][j];
            }
        }
        int i, j;
        cin >> i >> j;
        int res = bfs(t, d, i-1, j-1);
        if (res >= 0) cout << res << endl;
        else cout << "no" << endl;
    }

}