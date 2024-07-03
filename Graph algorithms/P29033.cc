#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Graf;

bool pintable(int x, int c, vector<int>& color, Graf& g) {
    if (color[x]) return color[x] == c;
    color[x] = c;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (not pintable(y, -c, color, g)) return false;
    }
    return true;
}

bool colorable(Graf& g, vector<int>& color) {
    for (int x = 0; x < g.size(); ++x) 
        if (not color[x] and not pintable(x, 1, color, g)) return false;
        return true;
}

int main () {
    int nodes, arestes;
    int x, y;
    while (cin >> nodes >> arestes) {
        Graf g(nodes, vector<int>());
        vector<int> color(nodes, 0);
        for (int i = 0; i < arestes; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << (colorable(g, color) ? "yes" : "no") << endl;
    }
}
