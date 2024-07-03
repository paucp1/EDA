#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

void bfs(vector<unordered_set<int>>& g) {
    int n = g.size();
    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        for (unordered_set<int>::iterator it = g[v].begin(); it != g[v].end(); ++it) {
            int v_aux = *it;
            if (dist[v_aux] == -1) {
                dist[v_aux] = dist[v] + 1;
                q.push(v_aux);
            }
        }
    }

    for (int i = 0; i < dist.size(); ++i) {
        cout << i << " : ";
        if (dist[i] >= 0) cout << dist[i] << endl;
        else cout << "no" << endl;
    }

    cout << "----------" << endl;
}


int main () {
    int n, t;
    while (cin >> n >> t) {
        vector<unordered_set<int>> g(n);
        for (int i = 0; i < t; ++i) {
            int c;
            cin >> c;
            vector<int> vec(c);
            for (int j = 0; j < c; ++j) {
                cin >> vec[j];
            }

            for (int j = 0; j < c; ++j) {
                for (int k = j+1; k < c; ++k){
                    int u = vec[j];
                    int v = vec[k];
                    g[u].insert(v);
                    g[v].insert(u);
                }
            }
        }

        bfs(g);
    }
}