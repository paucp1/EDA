#include <vector>
#include <iostream>
using namespace std;

int fixed_point_rec(const vector<int>& vec, int a, int e, int d){
    if (e > d) return -1;
    else {
        int m = (e+d)/2;
        if ((vec[m] + a) < m + 1) return fixed_point_rec(vec, a, m+1, d);
        else if ((vec[m] + a) > m + 1) return fixed_point_rec(vec, a, e, m-1);
        else {
            int aux = fixed_point_rec(vec, a, e, m-1);
            if (aux != -1) return aux;
            return m + 1;
        }
    }
}



int fixed_point(const vector<int>& vec, int a) {
    if (vec.empty()) return -1;
    else return fixed_point_rec(vec, a, 0, vec.size()-1);
}


int main () {
    int n, m, a;
    int n_seq = 1;
    while (cin >> n) {
        cout << "Sequence #" << n_seq << endl;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> a;
            int res = fixed_point(vec, a);
            if (res != -1) cout << "fixed point for " << a << ": " << res << endl;
            else cout << "no fixed point for " << a << endl;
        }
        cout << endl;
        ++n_seq;
    }
}