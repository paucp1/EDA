#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double>& v){
    if (v.empty()) return false;
    int l = 0, r = v.size()-1, mid;
    while (l+1 < r) {
        mid = (l+r)/2;
        if (v[mid] == x or v[mid-1] == x or v[mid+1] == x) return true;
        else if (v[mid] > x) r = mid;
        else l = mid;
    }
    return (v[l] == x or v[r] == x);
}

int main () {
    int n;
    while (cin >> n) {
        vector<double> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        double x;
        cin >> x;
        cout << resistant_search(x, vec);
    }
}