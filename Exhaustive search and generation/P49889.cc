#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char>& par) {
    int n = par.size();
    for (int i = 0; i < n; ++i) {
        cout << par[i];
    }
    cout << endl;
}

void paraules(vector<char>& par, const vector<char>& cons, const vector<char>& voc, int idx){
    int n = par.size();
    if (idx == n) escriu(par);
    else{
        if (idx%2 == 0) {
            for (int i = 0; i < cons.size(); ++i) {
                bool present = false;
                for (int j = 0; j < idx and not present; j += 2) {
                    if (par[j] == cons[i]) present = true;
                }

                if (not present) {
                    par[idx] = cons[i];
                    paraules(par, cons, voc, idx+1);
                }
            }
        }
        else {
            for (int i = 0; i < voc.size(); ++i) {
                bool present = false;
                for (int j = 1; j < idx and not present; j += 2){
                    if (par[j] == voc[i]) present = true;
                }

                if (not present) {
                    par[idx] = voc[i];
                    paraules(par, cons, voc, idx+1);
                }
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<char> par(2*n);
    vector<char> cons(n);
    vector<char> voc(n);
    for (int i = 0; i < n; ++i) {
        cin >> cons[i];
    }
    for (int i = 0; i < n; ++i){
        cin >> voc[i];
    }
    paraules(par, cons, voc, 0);
}