#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pos;
typedef vector<vector<int>> Tauler;

const vector<Pos> mov = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool valida(Pos p, int n, int m) {
    return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m;
}

int bfs(int n, int m, Pos& ini, Pos fi) {
    Tauler t(n, vector<int>(m, -1));
    t[ini.first][ini.second] = 0;
    queue<Pos> q;
    q.push(ini);
    while (not q.empty()) {
        Pos p = q.front();
        q.pop();
        if (p == fi) {
            ini = fi;
            return t[fi.first][fi.second];
        }
        for (int i = 0; i < 8; ++i) {
            Pos p_aux = make_pair(p.first + mov[i].first, p.second + mov[i].second);
            if (valida(p_aux, n, m) and t[p_aux.first][p_aux.second] == -1) {
                t[p_aux.first][p_aux.second] = t[p.first][p.second] + 1;
                q.push(p_aux);
            }
        }
    }
    return -1;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        int w, l;
        cin >> w >> l;
        int k;
        cin >> k;
        vector<Pos> vec(k);
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            vec[i] = Pos(x, y);
        }
        int punts = 0;
        int best = 0;
        int i = 0;
        bool stop = false;
        Pos p = make_pair(0, 0);
        while (i < k and not stop) {
            int aux = bfs(n, m, p, vec[i]);
            if (aux == -1) stop = true;
            else {
                punts += w;
                punts -= aux*l;
                if (punts > best) best = punts;
            }
            ++i;
        }
        cout << best << endl;
    }
}