#include <iostream>
#include <vector>
using namespace std;

int n, m;
int suma = 0;
typedef vector<vector<char> > Matriu;

int dfs(Matriu& Mat, int x, int y) {
    if (x < 0 or x >= n or y < 0 or y >= m) return 0; 
    if (Mat[x][y] == 'X') return 0;
    bool tresor = (Mat[x][y] == 't');
    Mat[x][y] = 'X';
    return tresor + dfs(Mat, x + 1, y) + dfs(Mat, x - 1, y) + dfs(Mat, x, y + 1) + dfs(Mat, x, y - 1);
}

int main () {
    cin >> n >> m;
    Matriu M(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            M[i][j] = c;
        }
    }
    int x, y;
    cin >> x >> y;
    suma = dfs(M, x - 1, y - 1);
    cout << suma << endl;
}
