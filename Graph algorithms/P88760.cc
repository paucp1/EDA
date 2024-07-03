#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

typedef pair<double, double> Punt;
typedef pair<Punt, pair<double, int>> Cercle;
typedef vector<Cercle> Riu;

double calcula_distancia_min(Cercle& c1, Cercle& c2) {
    double x = c2.first.first - c1.first.first;
    double y = c2.first.second - c1.first.second;
    x = x*x;
    y = y*y;
    double d = sqrt(x + y);
    return d - c1.second.first - c2.second.first;
}

int salts(Riu& riu, vector<int>& s, double d){
    int n = riu.size();
    queue<Cercle> q;
    q.push(riu[0]);
    while (not q.empty()) {
        Cercle c = q.front();
        q.pop();
        for (int j = 0; j < n; ++j) {
            Cercle c_aux = riu[j];
            if (j != c.second.second and s[j] == -1 and calcula_distancia_min(c, c_aux) <= d) {
                q.push(c_aux);
                s[j] = s[c.second.second] + 1;
            }
        }
        if (s[n-1] != -1) return s[n-1];
    }
    return s[n-1];
}


int main () {
    int n;
    double d;
    while (cin >> n >> d) {
        Riu riu(n);
        vector<int> s(n, -1);
        double x, y, r;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> r;
            riu[i] = make_pair(make_pair(x, y), make_pair(r, i));
        }

        s[0] = 0;
        int n_salts = salts(riu, s, d);
        if (n_salts >= 1) cout << n_salts << endl;
        else cout << "Xof!" << endl;
    }
}