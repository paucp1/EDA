#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second != p2.second) return p1.second > p2.second;
    return p1.first <= p2.first;
}


int main () {
    map<string, pair<bool, int>> serv;
    map<string, pair<bool, int>>::iterator it_1;
    string instr, jug1, jug2;
    while (cin >> instr >> jug1) {
        it_1 = serv.find(jug1);
        if (instr == "LOGIN") {
            if (it_1 == serv.end()) {
                serv.insert(make_pair(jug1, make_pair(true, 1200)));
            }
            else {
                it_1->second.first = true;
            }
        }
        
        else if (instr == "LOGOUT") {
            if (it_1 != serv.end()) {
                it_1->second.first = false;
            }
        }
        
        else if (instr == "PLAY") {
            cin >> jug2;
            map<string, pair<bool, int>>::iterator it_2 = serv.find(jug2);
            if (it_1 == serv.end() or it_2 == serv.end() or it_1 ->second.first == false or it_2 ->second.first == false) {
                cout << "jugador(s) no connectat(s)" << endl;
            }
            
            else {
                it_1->second.second += 10;
                if (it_2->second.second >= 1210)  it_2->second.second -= 10;
            }
        }
        
        else if (instr == "GET_ELO") {
            cout << it_1->first << " " << it_1->second.second << endl;
        }
    }
    
    cout << endl;
    cout << "RANKING" << endl;
    vector<pair<string, int>> vec(serv.size());
    int i = 0;
    for (it_1 = serv.begin(); it_1 != serv.end(); ++it_1) {
        vec[i] = make_pair(it_1->first, it_1->second.second);
        ++i;
    }
    sort(vec.begin(), vec.end(), compare);
    
    for (i = 0; i < vec.size(); ++i) {
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    
}
    
