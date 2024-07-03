#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Graf;

void escriu(vector<int>& prev) {
    int v = prev.size() - 1;
    stack<int> s;
    while (v != 0) {
        s.push(v);
        v = prev[v];
    }

    cout << "0";
    int size = s.size();
    for (int i = 0; i < size; ++i) {
        cout << " " << s.top();
        s.pop();
    }
    cout << endl;
}

void trobar_cami(Graf& g) {
    int n = g.size();
    queue<int> q;
    vector<int> prev(n, -1);
    prev[0] = 0;
    q.push(0);
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        if (v == n-1) {
            escriu(prev);
            return;
        }
        for (int i = 0; i < g[v].size(); ++i) {
            int v_aux = g[v][i];
            if (prev[v_aux] == -1) {
                prev[v_aux] = v;
                q.push(v_aux);
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for (int i = 0 ; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end());
        }
        trobar_cami(g);
    }
}