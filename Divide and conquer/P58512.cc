#include <iostream>
using namespace std;

double exp_rapida(double r, int m) {
    if (m == 0) return 1;
    else {
        double y = exp_rapida(r, m/2);
        if (m%2 == 0) return y*y;
        else return y*y*r;
    }

}

int interest_rates(double m, double f, double r, int min, int max) {
    if (min <= max) {
        int d = (min+max)/2;
        double v_bank = exp_rapida(r, d)*m;
        double v_prof = m + f*d;
        if (v_prof > v_bank) return interest_rates(m, f, r, d+1, max);
        else if (v_prof < v_bank) return interest_rates(m, f, r, min, d-1);
        else return d;
    }
    return min;
}

int main () {
    double m, f, r;
    while (cin >> m >> f >> r) {
        cout << interest_rates(m, f, 1+r/100, 1, 10000000) << endl;
    }
}