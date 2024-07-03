#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<int>& col, int f, int c) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            if (col[i] == j) cout << "R";
            else cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void torres(vector<int>& col, vector<bool>& b, int idx, int f, int c) {
    if (idx == f) escriu(col, f, c);
    else {
        for (int i = 0; i < b.size(); ++i) {
            if (not b[i]) {
                b[i] = true;
                col[idx] = i;
                torres(col, b, idx+1, f, c);
                b[i] = false;
            }
        }
    }
}

int main() {
    int f, c;
    cin >> f >> c;
    vector<int> col(f);
    vector<bool> b(c, false);
    torres(col, b, 0, f, c);
}
