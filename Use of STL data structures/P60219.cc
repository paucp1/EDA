#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp (string& s1, string& s2) {
    int size_1 = s1.size();
    int size_2 = s2.size();
    if (size_1 != size_2) return size_1 < size_2;
    return s1 < s2;
}

int main () {
    int game = 1;
    bool quit = false;
    while (not quit) {
        set<string> pres;
        set<string> not_pres;
        string word;
        while (cin >> word and word != "END" and word != "QUIT") {
            set<string>::iterator it_1 = pres.find(word);

            if (it_1 == pres.end()) {
                pres.insert(word);
                not_pres.erase(word);
            }
        
            if (it_1 != pres.end()) {
                pres.erase(word);
                not_pres.insert(word);
            }
        }
    
        vector<string> v(not_pres.size());
        int i= 0;
        for (set<string>::iterator it = not_pres.begin(); it != not_pres.end(); ++it) {
            v[i] = *it;
            ++i;
        }
        sort(v.begin(), v.end(), cmp);
    
        cout << "GAME #" << game << endl;
        cout << "HAS:" << endl;
        for (set<string>::iterator it = pres.begin(); it != pres.end(); ++it) {
            cout << *it << endl;
        }
        cout << endl;
        cout << "HAD:" << endl;
        for (i = 0; i < v.size(); ++i) {
            cout << v[i] << endl;
        }
        if (word != "QUIT") {
            cout << endl;
            ++game;
        }
        else quit = true;
    }
}
