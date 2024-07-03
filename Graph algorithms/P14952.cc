#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

void ordenacio_topologica(Graf& g, vector<int>& ordre, vector<int>& grau, int n) {
    priority_queue<int, vector<int>, greater<int>> s;
    for (int i = 0; i < n; ++i) {
        if (grau[i] == 0) s.push(i);
    }

    while(not s.empty()) {
        int v = s.top();
        s.pop();
        ordre.push_back(v);
        for (int i = 0; i < g[v].size(); ++i) {
            int v_aux = g[v][i];
            grau[v_aux] = grau[v_aux] - 1;
            if (grau[v_aux] == 0) s.push(v_aux);
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        vector<int> grau(n, 0);
        vector<int> ordre;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            ++grau[y];
        }
        ordenacio_topologica(g, ordre, grau, n);
        for (int i = 0; i < ordre.size(); ++i) {
            cout << ordre[i];
            if (i != ordre.size()-1) cout << " ";
        }
        cout << endl;
    }
}