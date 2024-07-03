#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pos;
typedef vector<vector<int>> Mat;

const int INF = 1e9;
const vector<pair<int, int>> mov = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool al_borde(Pos& v, int n) {
    return v.first == 0 or v.first == n-1 or v.second == 0 or v.second == n-1;
}

void dijkstra(Mat& m) {
    int n = m.size();
    Pos p(n/2, n/2);
    Mat dist(n, vector<int>(n, INF));
    Mat vist(n, vector<int>(n, 0));
    dist[p.first][p.second] = m[p.first][p.second];
    priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, greater<pair<int, Pos>>> q;
    q.push(make_pair(dist[p.first][p.second], p));

    while (not q.empty()) {
        int d = q.top().first;
        Pos v = q.top().second;
        q.pop();
        if (not vist[v.first][v.second]) {
            vist[v.first][v.second] = true;
            if (al_borde(v, n)) {
                cout << dist[v.first][v.second] << endl;
                return;
            }
            for (int i = 0; i < mov.size(); ++i) {
                Pos v_aux(v.first + mov[i].first, v.second + mov[i].second);
                if (dist[v_aux.first][v_aux.second] > dist[v.first][v.second] + m[v_aux.first][v_aux.second]) {
                    dist[v_aux.first][v_aux.second] = dist[v.first][v.second] + m[v_aux.first][v_aux.second];
                    q.push(make_pair(dist[v_aux.first][v_aux.second], v_aux));
                }
            }

        }
    }

}

int main () {
    int n;
    while (cin >> n) {
        Mat m(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
            }
        }
        dijkstra(m);
    }
}