#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Arc;
typedef vector<vector<Arc>> Graf;

const int INF = 1e9;

void bfs(Graf& g, vector<int>& pes_v, int ini, int fi) {
    if (ini == fi) {
        cout << "c(" << ini << "," << fi << ") = 0" << endl;
        return;
    }
    int n = g.size();
    vector<int> dis(n, INF);
    dis[ini] = 0;
    vector<bool> vis(n, false);
    priority_queue<Arc, vector<Arc>, greater<Arc>> q;
    q.push(Arc(0, ini));
    while (not q.empty()) {
        int v = q.top().second;
        int c = q.top().first;
        q.pop();
        if (v == fi) {
            cout << "c(" << ini << "," << fi << ") = " << dis[fi] - pes_v[fi] << endl;
            return;
        }

        if (not vis[v]) {
            vis[v] = true;
            for (int i = 0; i < g[v].size(); ++i) {
                int v_aux = g[v][i].second;
                int c_aux = g[v][i].first;
                if (dis[v_aux] > dis[v] + c_aux + pes_v[v_aux]) {
                    dis[v_aux] = dis[v] + c_aux + pes_v[v_aux];
                    q.push(Arc(dis[v_aux], v_aux));
                }
            }
        }
    }
    if (not vis[fi]) {
        cout << "c(" << ini << "," << fi << ") = +oo" << endl;
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    Graf g(n);
    vector<int> pes_v(n);
    for (int i = 0; i < n; ++i) {
        cin >> pes_v[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back(make_pair(c, y));
        g[y].push_back(make_pair(c, x));
    }

    int ini, fi;
    while (cin >> ini >> fi) {
        bfs(g, pes_v, ini, fi);
    }

}