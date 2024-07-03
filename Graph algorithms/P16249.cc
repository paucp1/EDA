#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

typedef vector<vector<string>> Graf;
typedef map<string, pair<int,int>> Tasks;

void ordenacio_topologica(Graf& g, Tasks& t, int n) {
    priority_queue<string, vector<string>, greater<string>> q;
    for (map<string, pair<int, int>>::iterator it = t.begin(); it != t.end(); ++it) {
        if (it->second.second == 0) q.push(it -> first);
    }

    queue<string> q_aux;
    while (not q.empty()) {
        string s = q.top();
        q.pop();
        q_aux.push(s);
        //cout << s;
        int i = t[s].first;
        for (int j = 0; j < g[i].size(); ++j) {
            string s_aux = g[i][j];
            if (--t[s_aux].second == 0) q.push(s_aux);
        }
    }

    if (q_aux.size() != n) {
        cout << "NO VALID ORDERING" << endl;
    }
    else {
        while (not q_aux.empty()) {
            cout << q_aux.front();
            q_aux.pop();
        }
        cout << endl;
    }
}

int main () {
    int n;
    while (cin >> n) {
        Graf g(n);
        Tasks t;
        for (int i = 0; i < n; ++i) {
            string task;
            cin >> task;
            t.insert(make_pair(task, make_pair(i, 0)));
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string task1, task2;
            cin >> task1 >> task2;
            int pos = t[task1].first;
            g[pos].push_back(task2);
            ++t[task2].second;
        }
        ordenacio_topologica(g, t, n);
    }

}