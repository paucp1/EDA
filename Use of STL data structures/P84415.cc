#include <iostream>
#include <map>
using namespace std;

int main () {
    map<string, int> bossa;
    string op;
    while (cin >> op) {
        if (op == "store") {
            string par;
            cin >> par;
            if (bossa.find(par) == bossa.end()) {
                bossa[par] = 1;
            }
            
            else ++bossa[par];
        }
        
        else if (op == "delete") {
            string par;
            cin >> par;
            if (bossa.find(par) != bossa.end()) {
                map<string, int>::iterator it = bossa.find(par);
                --it ->second;
                if (it -> second == 0) bossa.erase(par);
            }
        }
        
        else if (op == "minimum?") {
            if (bossa.empty()) cout << "indefinite minimum" << endl;
            else {
                cout << "minimum: ";
                map<string, int>::iterator it = bossa.begin();
                cout << it -> first << ", " << it -> second << " time(s)" << endl;
            }
        }
        
        else if (op == "maximum?") {
            if (bossa.empty()) cout << "indefinite maximum" << endl;
            else {
                cout << "maximum: ";
                map<string, int>::iterator it = bossa.end();
                --it;
                cout << it -> first << ", " << it -> second << " time(s)" << endl;
            }
        }
    }
}

        
        
