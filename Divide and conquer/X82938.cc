#include <vector>
#include <iostream>
using namespace std;

bool search_rec(int x, const vector<int>& v, int e, int d) {
    if (e > d) return false;
    else {
        int m = (e+d)/2;
        if (v[m] < x) {
            if (v[e] < v[d]) return search_rec(x, v, m+1, d);
            else return search_rec(x, v, e, m-1);
        }
        else if (v[m] > x) {
            if (v[e] < v[d]) return search_rec(x, v, e, m-1);
            else return search_rec(x, v, m+1, d); 
        }
        else return true;
    }
}

int trobar_j(const vector<int>& v, int e, int d) {
    if (e == d) return e;
    else if (d-e == 1) {
        if (v[e] < v[d]) return d;
        else return e;
    }

    else {
        int m = (e+d)/2;
        if (v[m] < v[m+1] and v[m] > v[m-1]) return trobar_j(v, m+1, d);
        else if (v[m] > v[m+1] and v[m] < v[m-1]) return trobar_j(v, e, m-1);
        else return m;
    }
}

bool search(int x, const vector<int>& v) {
    if (v.empty()) return false;
    else {
        int j = trobar_j(v, 0, v.size()-1);
        return search_rec(x, v, 0, j) or search_rec(x, v, j, v.size()-1);
    }
}


int main() {
int n;
    while (cin >> n){
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        int x;
        cin >> x;
        cout << search(x, vec) << endl;
    }
}