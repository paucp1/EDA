#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1e9;

typedef pair<int, int> Arc;
typedef vector<vector<Arc>> Graf;

void dijkstra(Graf& g, int ini, int fi, int n, int& cost, int& ways) {
    vector<int> dist(n, inf);
    vector<bool> vist(n, false);
    vector<int> w(n, 0);
    priority_queue<Arc, vector<Arc>, greater<Arc>> q;
    dist[ini] = 0;
    w[ini] = 1;
    q.push(Arc(0, ini));
    while (not q.empty()) {
        int v = q.top().second;
        int d = q.top().first;
        q.pop();
        if (v == fi) {
            cost = dist[v];
            ways = w[v];
            return;
        }
        if (not vist[v]) {
            vist[v] = true;
            for (int i = 0; i < g[v].size(); ++i) {
                int v_aux = g[v][i].second;
                int d_aux = g[v][i].first;
                if (dist[v_aux] > dist[v] + d_aux) {
                    dist[v_aux] = dist[v] + d_aux;
                    w[v_aux] = w[v];
                    q.push(Arc(dist[v_aux], v_aux));
                } 

                else if (dist[v_aux] == dist[v] + d_aux) {
                    w[v_aux] += w[v];
                }
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            g[u].push_back(Arc(c, v));
        }
        int ini, fi, cost = -1, ways = 0;
        cin >> ini >> fi;
        dijkstra(g, ini, fi, n, cost, ways);
        if (cost != -1) cout << "cost " << cost << ", " << ways << " way(s)" << endl;
        else cout << "no path from " << ini << " to " << fi << endl;
    }
}