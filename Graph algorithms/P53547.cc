#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> board;

void dfs_rec(vector<vector<int>>& B, int x, int y, int bishops_per_cela, int n, int m, int& residu){
    if (x >= 0 and x < n and y >= 0 and y < m and B[x][y] != -1){
        residu = residu + (B[x][y] - bishops_per_cela);
        B[x][y] = -1;
        dfs_rec(B, x+1, y+1, bishops_per_cela, n, m, residu);
        dfs_rec(B, x+1, y-1, bishops_per_cela, n, m, residu);
        dfs_rec(B, x-1, y+1, bishops_per_cela, n, m, residu);
        dfs_rec(B, x-1, y-1, bishops_per_cela, n, m, residu);
    }
}

bool repartir(vector<vector<int>>& B, int bishops_per_cela, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (B[i][j] != -1) {
                int residu = 0;
                dfs_rec(B, i, j, bishops_per_cela, n, m, residu);
                if (residu != 0) return false;
            }
        }
    }
    return true;
}


bool bishops(vector<vector<int>>& B, int valid_cells, int n_bishops, int n, int m) {
    if (valid_cells == 0) return true;
    if (n_bishops%valid_cells == 0) {
        int bishops_per_cela = n_bishops/valid_cells;
        return repartir(B, bishops_per_cela, n, m);
    }
    else return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m;
        int valid_cells = 0;
        int n_bishops = 0;
        cin >> n >> m;
        board B(n, vector<int>(m, -1));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                string valor;
                cin >> valor;
                if (valor != "X") {
                    ++valid_cells;
                    int num = atoi(valor.c_str());
                    n_bishops += num;
                    B[j][k] = num;
                }
            }
        }
        cout << "Case " << i+1 << ": " << (bishops(B, valid_cells, n_bishops, n, m) ? "yes" : "no") << endl;
    }
}
    
