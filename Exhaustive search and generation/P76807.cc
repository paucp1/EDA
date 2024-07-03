#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VVE = vector<VE>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;


VVE S(9, VE(9));
VVB fila, colu;
VVVB quad;


void escriu() {
  cout << endl;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) cout << (j ? " " : "") << S[i][j];
    cout << endl;
  }
}


bool sudoku(int i, int j) {
  if (i == 9) {
    escriu();
    return true;
  }
  
  if (j == 9) return sudoku(i + 1, 0);
  
  if (S[i][j]) return sudoku(i, j + 1);

  for (int x = 1; x <= 9; ++x)
    if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
      S[i][j] = x;
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
      if (sudoku(i, j + 1)) return true;
      S[i][j] = 0;
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
    }
  return false;
}


int main() {
  int t;
  cin >> t;
  cout << t << endl;
  while (t--) {
    fila = colu = VVB(9, VB(10, false));
    quad = VVVB(3, VVB(3, VB(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.') S[i][j] = 0;
        else {
          int x = c - '0';
          S[i][j] = x;
          fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
        }
      }
    sudoku(0, 0);
  }
}