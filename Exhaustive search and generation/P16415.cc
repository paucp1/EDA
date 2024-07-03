#include <iostream>
#include <vector>
using namespace std;

int reines(vector<int>& pos, vector<bool>& mc, vector<bool>& md1, vector<bool>& md2, int i) {
    int n = pos.size();
    if (i == n) return 1;
    else {
        int res = 0;
        for (int j = 0; j < n; ++j) {
            if (not mc[j] and not md1[i+j] and not md2[i - j + n + 1]) {
                pos[i] = j;
                mc[j] = md1[i+j] = md2[i - j + n + 1] = true;
                res += reines(pos, mc, md1, md2, i + 1);
                mc[j] = md1[i+j] = md2[i - j + n + 1] = false;
            }
        }
        return res;
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> pos(n);
    vector<bool> mc(n, false);
    vector<bool> md1(2*n-1, false);
    vector<bool> md2(2*n-1, false);
    int suma = reines(pos, mc, md1, md2, 0);
    cout << suma << endl;
}