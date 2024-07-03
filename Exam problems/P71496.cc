#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Arc;
typedef vector<vector<Arc>> Graf;

int retallades(Graf& g) {
    int n = g.size();
    vector<bool> vis(n, false);
    vis[0] = true;
    priority_queue<Arc, vector<Arc>, greater<Arc>> q;
    for (int i = 0; i < g[0].size(); ++i) {
        q.push(g[0][i]);
    }
    int sz = 1;
    int mant = 0;
    while (sz < n) {
        int c = q.top().first;
        int v = q.top().second;
        q.pop();
        if (not vis[v]) {
            vis[v] = true;
            for (int i = 0; i < g[v].size(); ++i) {
                q.push(g[v][i]);
            }
            ++sz;
            mant += c;
        }
    }
    return mant;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        int cost_total = 0;
        for (int i = 0; i < m; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            g[x].push_back(make_pair(c, y));
            g[y].push_back(make_pair(c, x));
            cost_total += c;
        }
        cout << cost_total - retallades(g) << endl;
    }
}