#include <iostream>
#include <map>
using namespace std;


int main () {
    int x, y, n;
    while (cin >> x >> y >> n) {
        int contador = 0;
        map<int, int> m;
        m[n] = contador;
        ++contador;
        bool trobat = false;
        while (not trobat) {
            if (n > 100000000) {
                cout << n << endl;
                trobat = true;
            }
            
            else if (n%2 == 0) {
                n = n/2 + x;
                if (m.find(n) != m.end()) {
                    map<int, int>::iterator it = m.find(n);
                    cout << contador - it -> second << endl;
                    trobat = true;
                }
                
                else {
                    m[n] = contador;
                }
            }
            
            else {
                n = 3*n + y;
                if (m.find(n) != m.end()) {                    
                    map<int, int>::iterator it = m.find(n);
                    cout << contador - it -> second << endl;
                    trobat = true;
                }
                
                else {
                    m[n] = contador;
                }
            }
            
            ++contador;
        }
    }
}
                    
                    
    

                
            
