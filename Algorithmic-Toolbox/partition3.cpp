#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
//using std::accumulate;

int partition3(vector<int> &A) {
  //write your code here
  int sum = accumulate(A.begin(), A.end(), 0);
  int length = A.size();
  if (length < 3 || sum % 3 != 0) return 0;
  int part_sum = sum / 3;
  int d[part_sum+1][length+1];

  for (int i = 0; i <= part_sum; ++i) {
    d[i][0] = 0;
  }

  for (int i = 0; i <= length; ++i) {
    d[0][i] = 0;
  }

  for (int i = 1; i <= part_sum; ++i) {
    for(int j = 1; j <= length; ++j) {
      int residual = i - A[j-1];
      if (residual == 0 || (residual > 0 && d[residual][j-1])) {
        if (d[i][j-1] == 0) {
          d[i][j] = 1;
        }
        else {
          d[i][j] = 2;
        }
      }
      else {
        d[i][j] = d[i][j-1];
      }
    }
  }

  if (d[part_sum][length] == 2) {
    return 1;
  }
  else {
    return 0;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
