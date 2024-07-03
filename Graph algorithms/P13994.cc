#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> P;
typedef vector<P> VP;
typedef vector<VP> Graf;
typedef vector<int> VE;

void dijkstra(Graf& g, int n, int ini, int fi) {
    VE dist(n, INF);
    VE pare(n);
    priority_queue<P> Q;
    dist[ini] = 0;
    Q.push(P(0,ini));
    while (not Q.empty()) {
        P p = Q.top();
        Q.pop();
        int d = -p.first;
        int x = p.second;
        if (d == dist[x]) { 
            if (x == fi) {
                stack<int> pila;
                while (x != ini) {
                    pila.push(x);
                    x = pare[x];
                }
                cout << ini;
                while (not pila.empty()) {
                    cout << " " << pila.top();
                    pila.pop();
                }
                cout << endl;
                return;
            }
            for (P arc : g[x]) {
                int y = arc.second;
                int d2 = d + arc.first;
                if (d2 < dist[y]) {
                    dist[y] = d2;
                    pare[y] = x;
                    Q.push(P(-d2,y));
                }
            }
        }
    }
    
    cout << "no path from " << ini << " to " << fi << endl;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        int ini, fi;
        Graf g(n);
        while (m--) {
            int x, y, c;
            cin >> x >> y >> c;
            g[x].push_back(P(c, y));
        }
        cin >> ini >> fi;
        dijkstra(g, n, ini, fi);
    }
        
}
