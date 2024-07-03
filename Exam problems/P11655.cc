#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<bool>& usat, vector<int>& num) {
    cout << "{";
    bool primer = true;
    for (int i = 0; i < usat.size(); ++i) {
        if (usat[i]) {
            if (not primer) cout << ",";
            cout << num[i];
            primer = false;
        }
    }
    cout << "}" << endl;
}

void suma(vector<bool>& usat, vector<int>& num, int s, int total, int sp, int idx) {
    if (idx == usat.size() and sp == s) escriu(usat, num);
    else if (idx < usat.size() and sp + total >= s){
        if (num[idx] + sp <= s) {
            usat[idx] = true;
            sp += num[idx];
            total -= num[idx];
            suma(usat, num, s, total, sp, idx+1);
            usat[idx] = false;
            sp -= num[idx];
        }

        suma(usat, num, s, total, sp, idx+1);
    }
}

int main () {
    int s, n;
    cin >> s >> n;
    int total = 0;
    int sp = 0;
    vector<int> num(n);
    vector<bool> usat(n, false);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num[i] = x;
        total += x;
    }
    suma(usat, num, s, total, sp, 0);
}