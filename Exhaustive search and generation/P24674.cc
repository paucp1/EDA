#include <iostream>
#include <vector>
using namespace std;

void escriure(const vector<string>& vec) {
    cout << "(";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size()-1) cout << ",";
    }
    cout << ")" << endl;
}

void permutacions(int idx, vector<string>& vec, const vector<string>& paraules) {
    if (idx == vec.size()) escriure(vec);
    else {
        for (int i = 0; i < paraules.size(); ++i) {
            bool present = false;
            for (int j = 0; j < idx and not present; ++j) {
                if (vec[j] == paraules[i]) present = true;
            }

            if (not present) {
                vec[idx] = paraules[i];
                permutacions(idx+1, vec, paraules);
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<string> vec(n);
    vector<string> paraules(n);
    for (int i = 0; i < n; ++i) {
        cin >> paraules[i];
    }
    permutacions(0, vec, paraules);
}