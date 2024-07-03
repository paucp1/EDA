#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> T;

bool posicio_valida(const T& t, int i, int j) {
    int n = t.size();
    if (t[i][j] == 'K') return false;
    else if (i-1 >= 0 and j-1 >= 0 and t[i-1][j-1] == 'K') return false;
    else if (i-1 >= 0 and t[i-1][j] == 'K') return false;
    else if (i-1 >= 0 and j+1 < n and t[i-1][j+1] == 'K') return false;
    else if (i+1 < n and j-1 >= 0 and t[i+1][j-1] == 'K') return false;
    else if (i+1 < n and t[i+1][j] == 'K') return false;
    else if (i+1 < n and j+1 < n and t[i+1][j+1] == 'K') return false;
    else if (j-1 >= 0 and t[i][j-1] == 'K') return false;
    else if (j+1 < n and t[i][j+1] == 'K') return false;
    else return true;
}

void escriu(T& t, int n_r, int r) {
    int n = t.size();
    if (n_r == r) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << t[i][j];
            }
            cout << endl;
        }
        cout << "----------" << endl;
    }
}

void colocar_reis(T& t, int n, int r, int n_r, int i, int j) {
    if (i == n) escriu(t, n_r, r);
    else if (j == n) colocar_reis(t, n, r, n_r, i+1, 0);
    else {
        if (posicio_valida(t, i, j) and n_r < r) {
            t[i][j] = 'K';
            colocar_reis(t, n, r, n_r + 1, i, j+1);
            t[i][j] = '.';
        }

        colocar_reis(t, n, r, n_r, i, j + 1);
    }
}

int main () {
    int n, r;
    cin >> n >> r;
    T t(n, vector<char>(n, '.'));
    colocar_reis(t, n, r, 0, 0, 0);
}