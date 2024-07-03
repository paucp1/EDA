#include <iostream>
#include <vector>
using namespace std;

int first_occurrence_rec(double x, const vector<double>& v, int e, int d) {
    if (e > d) return -1;
    else {
        int m = (e+d)/2;
        if (v[m] < x) return first_occurrence_rec(x, v, m + 1, d);
        else if (v[m] > x) return first_occurrence_rec(x, v, e, m - 1);
        else {
            if (m - 1 >= 0) {
                int pos = first_occurrence_rec(x, v, e, m - 1);
                if (pos != -1) return pos;
            }
            return m;
        }
    }
}

int first_occurrence(double x, const vector<double>& v) {
    if (v.empty() or x < v[0] or x > v[v.size()-1]) return -1;
    return first_occurrence_rec(x, v, 0, v.size()-1);
}

int main(){
    int n;
    cin >> n;
    vector<double> vec(n);
    for (int i = 0; i < n; ++i){
        cin >> vec[i];
    }
    double num;
    cin >> num;
    int res = first_occurrence(num, vec);
    if (res == -1) cout << num << " no apareix al vector" << endl;
    else cout << "La posicio de la primera aparició de " << num << " al vector es " << res << endl;
}

