#include <iostream>
#include <set>
using namespace std;

int main () {
    set<string> seq;
    set<string>::iterator median = seq.end();
    set<string>::iterator it;
    string par;
    while (cin >> par and par != "END") {
        seq.insert(par);
        it = seq.find(par);
        if (median == seq.end()) median = it;
        else if (seq.size()%2 == 0 and par < *median) --median;
        else if (seq.size()%2 != 0 and par > *median) ++median;
        cout << *median << endl;
    }
}
            
