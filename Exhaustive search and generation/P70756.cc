#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<pair<string, int>>& sol, int p) {
    for (int i = 1; i <= p; ++i) {
        bool first = true;
        cout << "subconjunt " << i << ": {";
        for (int j = 0; j < sol.size(); ++j) {
            int np = sol[j].second;
            if (j != 0 and np == i and not first) cout << ",";
            if (np == i) {
                cout << sol[j].first;
                first = false;
            }
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void particio(int idx, vector<pair<string, int>>& sol, vector<string>& par, int p) {
    int n = par.size();
    if (idx == n) escriu(sol, p);
    else {
        for (int i = 1; i <= p; ++i) {
            if (not sol[idx].second){
                sol[idx].second = i;
                particio(idx+1, sol, par, p);
                sol[idx].second = 0;
            }
        }
    }
}

int main () {
    int n, p;
    cin >> n;
    vector<string> par(n);
    vector<pair<string, int>> sol(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        par[i] = s;
        sol[i] = make_pair(s, 0);
    }
    cin >> p;
    particio(0, sol, par, p);
}