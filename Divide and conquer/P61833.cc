#include <iostream>
#include <vector>
using namespace std;

void power_matrix(vector<int>& vec, int n, int m) {

}

int main () {
    vector<int> vec(4);
    while(cin >> vec[0] >> vec[1] >> vec[2] >> vec[3]) {
        int n, m;
        cin >> n >> m;
        power_matrix(vec, n, m);
        for (int i = 0; i < 4; ++i) {
            cout << vec[i];
            if (i%2 == 0) cout << " ";
            else cout << endl;
        }
        cout << "----------" << endl;
    }
}