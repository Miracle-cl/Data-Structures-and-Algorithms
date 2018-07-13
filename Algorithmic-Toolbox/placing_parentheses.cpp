#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long to_digit(char c) {
  long long i = c - '0';
  return i;
}

long long get_maximum_value(const string &exp) {
  //write your code here
  vector<long long> d;
  vector<char> op;
  for (long long i = 0; i < exp.size(); ++i) {
    if (i % 2 == 0)
      d.push_back(to_digit(exp[i]));
    else
      op.push_back(exp[i]);
  }

  long long num_digit = d.size();
  long long minimum[num_digit][num_digit];
  long long maximum[num_digit][num_digit];

  for (long long i = 0; i < num_digit; ++i) {
    minimum[i][i] = d[i];
    maximum[i][i] = d[i];
  }

  for (long long s = 1; s < num_digit; ++s) {
    for (long long i = 0; i < num_digit-s; ++i) {
      long long j = i + s;
      //get min_v and max_v -- MinAndMax[i][j]
      long long min_v = INT_MAX;
      long long max_v = INT_MIN;
      for (long long k = i; k <= j-1; ++k) {
        long long a = eval(maximum[i][k], maximum[k+1][j], op[k]);
        long long b = eval(maximum[i][k], minimum[k+1][j], op[k]);
        long long c = eval(minimum[i][k], maximum[k+1][j], op[k]);
        long long d = eval(minimum[i][k], minimum[k+1][j], op[k]);
        min_v = min(min(min(min(min_v, a), b), c), d);
        max_v = max(max(max(max(max_v, a), b), c), d);
      }
      minimum[i][j] = min_v;
      maximum[i][j] = max_v;
    }
  }

  return maximum[0][num_digit-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
