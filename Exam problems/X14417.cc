#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<string>> Teclat;
typedef vector<vector<int>> Dist;

void bfs(Teclat& t, string p, int& cops, int& i, int& j, bool& posible) {
    int n = t.size();
    int m = t[0].size();
    Dist dis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    dis[i][j] = 0;
    q.push(make_pair(i, j));
    while (not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (t[x][y] == p) {
            ++cops;
            cops += dis[x][y];
            i = x;
            j = y;
            return;
        }

        if (x-1 >= 0 and dis[x-1][y] == -1 and t[x-1][y] != "*") {
            dis[x-1][y] = dis[x][y] + 1;
            q.push(make_pair(x-1, y));
        }

        if (y-1 >= 0 and dis[x][y-1] == -1 and t[x][y-1] != "*") {
            dis[x][y-1] = dis[x][y] + 1;
            q.push(make_pair(x, y-1));
        }

        if (y+1 < m and dis[x][y+1] == -1 and t[x][y+1] != "*") {
            dis[x][y+1] = dis[x][y] + 1;
            q.push(make_pair(x, y+1));
        }

        if (x+1 < n and dis[x+1][y] == -1 and t[x+1][y] != "*") {
            dis[x+1][y] = dis[x][y] + 1;
            q.push(make_pair(x+1, y));
        }
    }
    posible = false;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Teclat t(n, vector<string>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> t[i][j];
            }
        }
        int p;
        cin >> p;
        vector<string> par(p);
        for (int i = 0; i < p; ++i) {
            cin >> par[i];
        }

        int cops = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        bool posible = true;
        while (k < p and posible) {
            bfs(t, par[k], cops, i, j, posible);
            ++k;
        }

        if (posible) cout << cops << endl;
        else cout << "impossible" << endl;
    }
}