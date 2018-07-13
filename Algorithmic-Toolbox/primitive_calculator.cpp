#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// greedy calculator
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

// dynamic programming
vector<int> optimal_sequence_dp(int n) {
  std::vector<int> sequence;
  std::vector<int> min_num(n+1);
  min_num[0] = 0;
  min_num[1] = 0;

  // calculate the minmum number
  for (int m = 2; m <= n; ++m) {
    min_num[m] = min_num[m-1] + 1;
    if (m % 2 == 0) {
      if (min_num[m/2] < (min_num[m] - 1)) min_num[m] = min_num[m/2] + 1;
    }
    if (m % 3 == 0) {
      if (min_num[m/3] < (min_num[m] - 1)) min_num[m] = min_num[m/3] + 1;
    }
  }

  // output the sequence
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      if (min_num[n] == min_num[n/3] + 1) {
        n /= 3;
        continue;
      }
    }
    if (n % 2 == 0) {
      if (min_num[n] == min_num[n/2] + 1) {
        n /= 2;
        continue;
      }
    }
    if (min_num[n] == min_num[n-1] + 1) {
      --n;
      continue;
    }
    --n;
  }

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
