#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1e9;
typedef pair<int, int> Arc;
typedef vector<vector<Arc>> Graf;

int dijkstra(Graf& g, int ini, int fi, int n) {
    vector<int> dist(n, inf);
    vector<bool> visitat(n, false);
    dist[ini] = 0;
    priority_queue<Arc, vector<Arc>, greater<Arc>> q;
    q.push(Arc(0, ini));
    while (not q.empty()) {
        int v = q.top().second;
        int d = q.top().first;
        q.pop();
        if (v == fi) return dist[v];
        if (not visitat[v]) {
            visitat[v] = true;
            for (int i = 0; i < g[v].size(); ++i) {
                int v_aux = g[v][i].second;
                int d_aux = g[v][i].first;
                if (dist[v_aux] > dist[v] + d_aux) {
                    dist[v_aux] = dist[v] + d_aux;
                    q.push(Arc(dist[v_aux], v_aux));
                }
            }
        }
    }
    return -1;
}


int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            g[u].push_back(Arc(c,v));
        }
        int ini, fi;
        cin >> ini >> fi;
        int res = dijkstra(g, ini, fi, n);
        if (res != -1) cout << res << endl;
        else cout << "no path from " << ini << " to " << fi << endl;
    } 
    
}