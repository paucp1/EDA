#include <iostream>
#include <map>
#include <set>
using namespace std;

void escriure(map<string, string>& parelles, set<string>& sols) {
    cout << "PARELLES:" << endl;
    for (map<string, string>::iterator it = parelles.begin(); it != parelles.end(); ++it) {
        if ((*it).first < (*it).second) {
            cout << (*it).first << " " << (*it).second << endl;
        }
    }
    cout << "SOLS:" << endl;
    for (set<string>::iterator it = sols.begin(); it != sols.end(); ++it) {
        cout << *it << endl;
    }
    cout << "----------" << endl;
}

int main () {
    string inst;
    map<string, string> parelles;
    set<string> sols;
    while (cin >> inst) {
        if (inst == "liats") {
            string x, y;
            cin >> x >> y;
            map<string, string>::iterator itx = parelles.find(x);
            map<string, string>::iterator ity = parelles.find(y);
            if (itx != parelles.end()) {
                string ex = (*itx).second;
                sols.insert(ex);
                parelles.erase(ex);
            }

            if (ity != parelles.end()) {
                string ex = (*ity).second;
                sols.insert(ex);
                parelles.erase(ex);
            }

            set<string>::iterator itx_s = sols.find(x);
            set<string>::iterator ity_s = sols.find(y);
            if (itx_s != sols.end()) {
                sols.erase(x);
            }

            if (ity_s != sols.end()) {
                sols.erase(y);
            }
            parelles[x] = y;
            parelles[y] = x;
        }

        if (inst == "info") {
            escriure(parelles, sols);
        }
    }
}