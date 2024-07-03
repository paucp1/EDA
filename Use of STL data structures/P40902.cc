#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    string nom, operacio;
    while (cin >> nom >> operacio) {
        if (operacio == "enters") {
            if (m.find(nom) != m.end()) cout << nom << " is already in the casino" << endl;
            else m[nom] = 0;
        }
        
        else if (operacio == "leaves") {
            if (m.find(nom) == m.end()) cout << nom << " is not in the casino" << endl;
            else {
                map<string, int>::iterator it = m.find(nom);
                cout << it -> first << " has won " << it -> second << endl;
                m.erase(nom);
            }
        }
        
        else if (operacio == "wins") {
            int var;
            cin >> var;
            if (m.find(nom) == m.end()) cout << nom << " is not in the casino" << endl;
            else {
                m[nom] = m[nom] + var;
            }
        }
    }
    
    cout << "----------" << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it ->first << " is winning " << it -> second << endl;
    }
}
              
           
            
