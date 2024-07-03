#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef vector<vector<int>> Dist;

int bfs(Tauler& t, Dist& d, int x, int y) {
    int n = t.size();
    int m = t[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (not q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        if (t[i][j] == 't') return d[i][j];

        if (i-1 >= 0 and i-1 < n and d[i-1][j] == -1 and t[i-1][j] != 'X') {
            q.push(make_pair(i-1, j));
            d[i-1][j] = d[i][j] + 1;
        }

        if (i+1 >= 0 and i+1 < n and d[i+1][j] == -1 and t[i+1][j] != 'X') {
            q.push(make_pair(i+1, j));
            d[i+1][j] = d[i][j] + 1;
        }

        if (j-1 >= 0 and j-1 < m and d[i][j-1] == -1 and t[i][j-1] != 'X') {
            q.push(make_pair(i, j-1));
            d[i][j-1] = d[i][j] + 1;
        }

        if (j+1 >= 0 and j+1 < m and d[i][j+1] == -1 and t[i][j+1] != 'X') {
            q.push(make_pair(i, j+1));
            d[i][j+1] = d[i][j] + 1;
        }
    }
    return -1;
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    Tauler t(n, vector<char> (m));
    Dist d(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }
    
    cin >> x >> y;
    d[x-1][y-1] = 0;
    int res = bfs(t, d, x - 1, y - 1);
    if (res >= 0) cout << "distancia minima: " << res << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
}
