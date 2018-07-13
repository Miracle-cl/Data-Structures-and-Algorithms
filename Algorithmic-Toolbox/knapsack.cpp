#include <iostream>
#include <vector>

// using std::vector;
using namespace std;

int optimal_weight(int limitW, const vector<int> &w) {
  //write your code here
  int n = w.size();
  if (n == 0) return 0;
  int d[limitW+1][n+1];

  for (int i = 0; i <= n; ++i) {
    d[0][i] = 0;
  }

  for (int weight = 0; weight <= limitW; ++weight) {
    d[weight][0] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int weight = 1; weight <= limitW; ++weight) {
      d[weight][i] = d[weight][i-1];
      if (w[i-1] <= weight) {
        int val = d[(weight-w[i-1])][i-1] + w[i-1];
        if (val > d[weight][i]) {
          d[weight][i] = val;
        }
      }
    }
  }
  return d[limitW][n];
}

int main() {
  int n, limitW;
  cin >> limitW >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(limitW, w) << '\n';
}
