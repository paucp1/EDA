#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& pos){
    int n = pos.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pos[i] != j) cout << ".";
            else cout << "Q";
        }
        cout << endl;
    }
    cout << endl;
}

void reines(vector<int>& pos, vector<bool>& mc, vector<bool>& md1, vector<bool>& md2, int i) {
    int n = pos.size();
    if (i == n) escriu(pos);
    else {
        for (int j = 0; j < n; ++j) {
            if (not mc[j] and not md1[i+j] and not md2[i-j+n+1]) {
                pos[i] = j;
                mc[j] = md1[i+j] = md2[i-j+n+1] = true;
                reines(pos, mc, md1, md2, i + 1);
                mc[j] = md1[i+j] = md2[i-j+n+1] = false;
            }
        }
    } 
}

int main() {
    int n;
    cin >> n;
    vector<int> pos(n, -1);
    vector<bool> mc(n, false);
    vector<bool> md1(2*n-1, false);
    vector<bool> md2(2*n-1, false);
    reines(pos, mc, md1, md2, 0);
}