#include <iostream>
#include <vector>
using namespace std;

void escriure(const vector<int>& vec) {
    cout << "(";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size()-1) cout << ",";
    }
    cout << ")" << endl;
}

void cadena(int idx, vector<int>& vec, vector<bool>& vis) {
    if (idx == vec.size()) escriure(vec);
    else {
        for (int i = 0; i < vec.size(); ++i) {
            if (not vis[i]) {
                vec[idx] = i+1;
                vis[i] = true;
                cadena(idx+1, vec, vis);
                vis[i] = false;
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<bool> vis(n, false);
    cadena(0, vec, vis);
}