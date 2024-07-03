#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> cua;
    char operacio;
    while (cin >> operacio) {
        if (operacio == 'S') {
          int x;
          cin >> x;
          cua.push(x);
        }
        
        if (operacio == 'A') {
            if (not cua.empty()) {
                cout << cua.top() << endl;
            }
            else {
                cout << "error!" << endl;
            }
        }
        
        if (operacio == 'R') {
            if (not cua.empty()) {
                cua.pop();
            }
            else {
                cout << "error!" << endl;
            }
        }
        
        if (operacio == 'I') {
            int x;
            cin >> x;
            if (not cua.empty()) {
                int max = cua.top();
                cua.pop();
                max = max + x;
                cua.push(max);
            }
            
            else {
                cout << "error!" << endl;
            }
        }
        
        if (operacio == 'D') {
            int x;
            cin >> x;
            if (not cua.empty()) {
                int max = cua.top();
                cua.pop();
                max = max - x;
                cua.push(max);
            }
            
            else {
                cout << "error!" << endl;
            }
        }
    }
}
