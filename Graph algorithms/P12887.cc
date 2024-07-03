#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Arc;
typedef vector<vector<Arc>> Graf;

void mst(Graf& g, int n) {
    vector<bool> vist(n, false);
    priority_queue<Arc, vector<Arc>, greater<Arc>> q;
    vist[0] = true;
    for (int i = 0; i < g[0].size(); ++i) {
        q.push(g[0][i]);
    }
    int sz = 1;
    int sum = 0;
    while (sz < n) {
        int c = q.top().first;
        int x = q.top().second;
        q.pop();
        if (not vist[x]) {
            vist[x] = true;
            for (int i = 0; i < g[x].size(); ++i) {
                q.push(g[x][i]);
            }
            sum += c;
            ++sz;
        }
    }
    cout << sum << endl;
}

int main ( ){
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u-1].push_back(make_pair(c, v-1));
            g[v-1].push_back(make_pair(c, u-1));
        }
        mst(g, n);
    }
}