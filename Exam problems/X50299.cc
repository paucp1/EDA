#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Arc;
typedef vector<vector<Arc>> Graf;

const int INF = 1e9;

void dijkstra(Graf& g) {
    int n = g.size();
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    dist[0] = 0;
    priority_queue<Arc, vector<Arc>, greater<Arc>> q;
    vector<bool> vis(n, false);
    q.push(Arc(0, 0));
    while (not q.empty()) {
        int v = q.top().second;
        int c = q.top().first;
        q.pop();
        if (v == 1) {
            cout << dist[v] << endl;
            return;
        }
        if (not vis[v]) {
            vis[v] = true;
            for (int i = 0; i < g[v].size(); ++i) {
                int v_aux = g[v][i].second;
                int c_aux = g[v][i].first;
                int d2 = max(c_aux, dist[v]);
                if (d2 < dist[v_aux]) {
                    dist[v_aux] = d2;
                    q.push(Arc(d2, v_aux));
                }
            }
        }

    }

}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for (int i = 0; i < m; ++i) {
            int x, y, l;
            cin >> x >> y >> l;
            g[x].push_back(Arc(l, y));
        }
        dijkstra(g);
    }
}