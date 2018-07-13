#include <iostream>
#include <vector>

using std::vector;
//using std::min;
using std::max;

// naive recursive implementation
int lcs1(vector<int> &a, vector<int> &b, int n, int m) {
  if (m == 0 || n == 0) return 0;
  if (a[n-1] == b[m-1]) {
    return 1 + lcs1(a, b, n-1, m-1);
  }
  else {
    return max(lcs1(a, b, n, m-1), lcs1(a, b, n-1, m));
  }
}


int lcs2(vector<int> &a, vector<int> &b, int n, int m) {
  //write your code here
  int d[n+1][m+1];

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i == 0 || j == 0) {
        d[i][j] = 0;
        continue;
      }
      if (a[i-1] == b[j-1]) {
        d[i][j] = d[i-1][j-1] + 1;
      }
      else {
        d[i][j] = max(d[i][j-1], d[i-1][j]);
      }
    }
  }
  return d[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b, n, m) << std::endl;
  //std::cout << lcs1(a, b, n, m) << std::endl;
}
