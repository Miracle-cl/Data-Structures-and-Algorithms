#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

// long long MaxPairwiseProduct(const vector<int>& numbers) {
//   long long result = 0;
//   int n = numbers.size();
//   for (int i = 0; i < n; ++i) {
//     for (int j = i + 1; j < n; ++j) {
//       if (numbers[i] * numbers[j] > result) {
//         result = numbers[i] * numbers[j];
//       }
//     }
//   }
//   return result;
// }

long long MaxPairwiseProduct(const vector<int>& numbers) {
    int n = numbers.size();

    int max_idx1 = -1;
    for (int i = 0; i < n; i++)
        if ((max_idx1 == -1) || (numbers[i] > numbers[max_idx1]))
            max_idx1 = i;

    int max_idx2 = -1;
    for (int j = 0; j < n; j++)
        if ((j != max_idx1) && ((max_idx2 == -1) || (numbers[j] > numbers[max_idx2])))
            max_idx2 = j;
    return ((long long) numbers[max_idx1]) * numbers[max_idx2];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
