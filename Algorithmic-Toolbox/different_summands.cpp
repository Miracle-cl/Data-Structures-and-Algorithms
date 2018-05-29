#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    //write your code here
    int i = 1;
    int sum = 1;
    //summands.push_back(i)
    while (sum <= n) {
        summands.push_back(i);
        i++;
        sum += i;
    }
    summands.pop_back();
    summands.push_back(n + 2 * i - 1 - sum);
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
