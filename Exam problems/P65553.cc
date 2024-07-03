#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        int jocs = n;
        map<string, int> m;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (m.find(s) == m.end()) m[s] = 1;
            else ++m[s];
        }

        int j;
        cin >> j;
        for (int i = 0; i < j; ++i) {
            string s;
            cin >> s;
            if (m.find(s) == m.end()) {
                m[s] = 1;
                ++jocs;
            }
            else {
                if (m[s] < (jocs) - m[s]) {
                    ++m[s];
                    ++jocs;
                }
            }
        }

        for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
            cout << (*it).first << " " << (*it).second << endl;
        }
        cout << "--------------------" << endl;
    }
}