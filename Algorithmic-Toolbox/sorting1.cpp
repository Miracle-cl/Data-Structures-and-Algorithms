#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

//6 6 0 4 8 7 6 4 7 5 is wrong

// int partition2(vector<int> &a, int l, int r) {
//   int x = a[l];
//   int j = l;
//   for (int i = l + 1; i <= r; i++) {
//     if (a[i] <= x) {
//       j++;
//       swap(a[i], a[j]);
//     }
//   }
//   swap(a[l], a[j]);
//   return j;
// }

struct Mid_num {
  int begin;
  int end;
};


Mid_num partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int i = l;
  int lt = l; // part less than x
  int gt = r; // part greater than x
  while (i < gt) {
    if (a[i] < x) {
      swap(a[i], a[lt]);
      ++lt;
      ++i;
    }
    else {
      if (a[i] > x) {
        swap(a[i], a[gt]);
        --gt;
      }
      else {
        ++i;
      }
    }
  }
  Mid_num s;
  s.begin = lt;
  s.end = gt;
  return s;
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  Mid_num s = partition3(a, l, r);

  randomized_quick_sort(a, l, s.begin - 1);
  randomized_quick_sort(a, s.end + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
