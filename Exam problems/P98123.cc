#include <iostream>
#include <set>
using namespace std;

int main () {
    int c;
    long residu = -1;
    unsigned long total = 0;
    string accio;
    int valor;
    cin >> c;
    set<long> bossa, s;
    while (cin >> accio >> valor) {
        if (accio == "deixar") {
            s.insert(valor);
            if (bossa.size() < c) {
                bossa.insert(valor);
                total += valor;
            }
            else {
                set<long>::iterator it = bossa.begin();
                if (valor > *it) {
                    total -= *it;
                    residu = *it;
                    bossa.erase(it);
                    total += valor;
                    bossa.insert(valor);
                }
                else if (valor > residu) residu = valor;
            }
        }

        if (accio == "endur") {
            set<long>::iterator it = s.find(valor);
            if (*it == residu) {
                if (it == s.begin()) residu = -1;
                else {
                    --it;
                    residu = *it;
                }
            }
            s.erase(valor);
            it = bossa.find(valor);
            if (it != bossa.end()) {
                bossa.erase(valor);
                total -= valor;
                if (residu > 0) {
                    bossa.insert(residu); 
                    total += residu;
                    it = s.find(residu);
                    if (it != s.begin()) {
                        --it;
                        residu = *it;
                    }
                    else residu = -1;
                } 
            }
        }

        cout << total << endl;
    }
}