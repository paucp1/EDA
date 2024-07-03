#include <iostream>
#include <vector>
using namespace std;

int n, m;
typedef vector<vector<char> > Matriu;

bool dfs(Matriu& Mat, int x, int y) {
    if (x < 0 or x >= n or y < 0 or y >= m) return false; 
    if (Mat[x][y] == 'X') return false;
    if (Mat[x][y] == 't') return true;
    Mat[x][y] = 'X';
    return dfs(Mat, x + 1, y) or dfs(Mat, x - 1, y) or dfs(Mat, x, y + 1) or dfs(Mat, x, y - 1);
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
    bool t = dfs(M, x - 1, y - 1);
    if (t) cout << "yes" << endl;
    else cout << "no" << endl;
}
