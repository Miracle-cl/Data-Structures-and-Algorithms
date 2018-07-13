#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
//using std::accumulate;

// https://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/

//recursive solution
int recursive_procedure(vector<int> &A, int n, int sum) {
  if (sum == 0) return 1;
  if (n == 0 && sum != 0) return 0;
  // if last element is greater than sum then ignore it
  if (A[n-1] > sum) {
      return recursive_procedure(A, n-1, sum);
  }
  else {
      return recursive_procedure(A, n-1, sum) || recursive_procedure(A, n-1, sum-A[n-1]);
  }
}

int recursive_p2(vector<int> &A, int n) {
  int sum = accumulate(A.begin(), A.end(), 0);
  int length = A.size();
  if (length < 2 || sum % 2 != 0) return 0;
  return recursive_procedure(A, length, sum/2);
}


// dynamic programming solution
int dp_partition2(vector<int> &A) {
  //write your code here
  int sum = accumulate(A.begin(), A.end(), 0);
  int length = A.size();
  if (length < 2 || sum % 2 != 0) return 0;
  int part_sum = sum / 2;
  int d[part_sum+1][length+1];

  for (int i = 1; i <= part_sum; ++i) {
    d[i][0] = 0; // 0 elements -- first column except first row
  }

  for (int i = 0; i <= length; ++i) {
    d[0][i] = 1; // first row = 1
  }

  for (int i = 1; i <= part_sum; ++i) {
    for(int j = 1; j <= length; ++j) {
      d[i][j] = d[i][j-1];
      if (i >= A[j-1]) {
          d[i][j] = d[i][j-1] || d[i - A[j-1]][j-1]; // i = sum
      }
    }
  }
  return d[part_sum][length];
}


int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << dp_partition2(A) << '\n';
}
