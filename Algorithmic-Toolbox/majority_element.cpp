#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    //write your code here
    sort(a.begin(), a.end());
    int mid_value = a[(left + right) / 2];
    int count = 0;
    for (int i = (left + right) / 2; i >= left; --i) {
        if (a[i] == mid_value)
            ++count;
        else
            break;
    }
    for (int i = (left + right) / 2 + 1; i < right; ++i) {
        if (a[i] == mid_value)
            ++count;
        else
            break;
    }
    if (count > right / 2)
        return 1;
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
