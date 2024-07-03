#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

bool cicles (const Graf& g) {
    int n = g.size();
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; ++u){
        for (int v : g[u]) {
            ++indeg[v];
        }
    }

    vector<int> cands;
    for (int u = 0; u < n; ++u) {
        if (indeg[u] == 0) cands.push_back(u);
    }

    while (not cands.empty()) {
        int u = cands.back ();
        cands.pop_back ();
        --n;
        for (int v : g[u]) {
            --indeg[v];
            if (indeg[v] == 0)
            cands.push_back(v);
        }
    }
    return n > 0;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);

        }
        if (cicles(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}