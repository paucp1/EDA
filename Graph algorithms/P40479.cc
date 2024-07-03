#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > tauler;

typedef vector<vector<bool> > matriu;

int pinta_rec(tauler& t, int i, int j, char c, matriu& m) {
    if (not m[i][j]) {
        m[i][j] = true;
        if (t[i][j] == '#') return 0;
        if (t[i][j] == '.') t[i][j] = c;
        pinta_rec(t, i - 1, j, c, m);
        pinta_rec(t, i, j - 1, c, m);
        pinta_rec(t, i, j + 1, c, m);
        pinta_rec(t, i + 1, j, c, m);
    }
    return 0;
}

void pinta(tauler& t, matriu& m) {
    for (int i = 1; i < t.size() - 1; ++i) {
        for (int j = 1; j < t[i].size() - 1; ++j) {
            if (t[i][j] != '.' and t[i][j] != '#') pinta_rec(t, i, j, t[i][j], m);
        }
    }
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            cout << t[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        tauler t(n, vector<char> (m));
        matriu mat(n, vector<bool> (m, false));
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> t[i][j];
            }
        }
        pinta(t, mat);
    }
}
    
