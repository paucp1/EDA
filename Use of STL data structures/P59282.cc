#include <iostream>
#include <map>
using namespace std;

int main () {
    cout.precision(4);
    cout.setf(ios::fixed);
    map<int, int> c;
    int suma = 0;
    double nombre = 0.0;
    int min, max;
    bool first = true;
    string op;
    while (cin >> op) {
        if (op == "number") {
            int num;
            cin >> num;
            if (first) {
                min = num;
                max = num;
                first = false;
            }
            if (num < min) min = num;
            if (num > max) max = num;
            suma += num;
            ++nombre;
            if (c.find(num) == c.end()) {
                c[num] = 1;
            }
            else {
                ++c[num];
            }
            
        }
        
        if (op == "delete") {
            if (not c.empty()) {
                suma -= min;
                --nombre;
                map<int, int>::iterator it = c.begin();
                --it -> second;
                if (it -> second == 0) {
                    c.erase(min);
                    map<int, int>::iterator aux = c.begin();
                    if (aux == c.end()) {
                        first = true;
                    }
                    else {
                        min = aux -> first;
                    }
                }
            }
        }
        
        if (c.empty()) cout << "no elements" << endl;
        else {
            cout << "minimum: " << min << ", maximum: " << max << ", average: " << suma/nombre << endl;
        }
    }
}
                
                
