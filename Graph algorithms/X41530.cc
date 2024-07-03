#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Bosc;

void dfs(int x, int& nv, int& na, Bosc& b, vector<bool>& vist) {
    if (vist[x]) return;
    vist[x] = true;
    ++nv;
    for (int y : b[x]) {
        ++na;
        dfs(y, nv, na, b, vist);
    }
}


void bosc(Bosc& b, int n, int m, vector<bool>& vist) {
    int res = 0;
    for (int x = 0; x < n; ++x) {
        if (not vist[x]) {
            int nv = 0;
            int na = 0;
            dfs(x, nv, na, b, vist);
            if (na != 2*(nv - 1)) {
                cout << "no" << endl;
                return;
            }
            ++res;
        }
    }
    cout << res << endl;
}

int main () {
    int n, m;
    int x, y;
    while (cin >> n >> m) {
        Bosc b(n, vector<int>());
        vector<bool> vist(n, false);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            b[x].push_back(y);
            b[y].push_back(x);
        }
        bosc(b, n, m, vist);
    }
}

        
        
