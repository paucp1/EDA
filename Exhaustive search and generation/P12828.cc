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

void zeros_uns(int idx, vector<int>& vec) {
    if (idx == vec.size()) escriu(vec);
    else {
        vec[idx] = 0;
        zeros_uns(idx + 1, vec);
        vec[idx] = 1;
        zeros_uns(idx + 1, vec);
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> vec(n);
    zeros_uns(0, vec);
}