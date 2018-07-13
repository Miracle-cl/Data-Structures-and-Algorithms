#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int an, int bn, int cn) {
  //write your code here
  int d[an+1][bn+1][cn+1];

  for (int i = 0; i <= an; ++i) {
    for (int j = 0; j <= bn; ++j) {
      for (int k = 0; k <= cn; ++k) {
        if (i == 0 || j ==0 || k == 0) {
          d[i][j][k] = 0;
          continue;
        }
        if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
          d[i][j][k] = d[i-1][j-1][k-1] + 1;
        }
        else {
          d[i][j][k] = max(d[i-1][j][k], max(d[i][j-1][k], d[i][j][k-1]));
        }
      }
    }
  }
  return d[an][bn][cn];
}


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c, an, bn, cn) << std::endl;
}
