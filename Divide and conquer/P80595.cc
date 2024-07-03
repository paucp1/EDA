#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& vec, int e, int d, int m, int& inversions) {
    vector<int> B(d-e+1);
    int i = e;
    int j = m+1;
    int k = 0;
    while (i <= m and j <= d) {
        if (vec[i] <= vec[j]) {
            B[k++] = vec[i++];
        }
        else {
            B[k++] = vec[j++];
            inversions += (m+1-i);
        }
    }
    while(i <= m) B[k++] = vec[i++];
    while(j <= d) B[k++] = vec[j++];
    for (k = 0; k <= d-e; ++k) vec[e + k] = B[k];
}

void mergesort(vector<int>& vec, int e, int d, int& inversions){
    if (e < d) {
        int m = (e+d)/2;
        mergesort(vec, e, m, inversions);
        mergesort(vec, m+1, d, inversions);
        merge(vec, e, d, m, inversions);
    }
}

void mergesort(vector<int>& vec, int& inversions) {
    mergesort(vec, 0, vec.size()-1, inversions);
}

int main () {
    int n;
    while (cin >> n) {
        vector<int> vec(n);
        int inversions = 0;
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        mergesort(vec, inversions);
        cout  << inversions << endl;
    }
}