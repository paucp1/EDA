#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        cout  << vec[i];
        if (i != n-1) cout << " ";
    }
    cout << endl;
}

void zeros_uns(int idx, vector<int>& vec, int n_u, int u, int n_z, int z) {
    if (idx == vec.size()) escriu(vec);
    else {
        if (n_z < z) {
            vec[idx] = 0;
            zeros_uns(idx+1, vec, n_u, u, n_z+1, z);
        }

        if (n_u < u) {
            vec[idx] = 1;
            zeros_uns(idx+1, vec, n_u+1, u, n_z, z);
        }
    }
}

int main () {
    int n, u;
    cin >> n >> u;
    vector<int> vec(n);
    int n_u = 0;
    int n_z = 0;
    zeros_uns(0, vec, n_u, u, n_z, n - u);
}