#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size();
    //write your code here
    if (x < a[left] || x > a[right-1]) return -1;
    if (x == a[left]) return 0;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) left = mid;
        if (a[mid] > x) right = mid;
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        // std::cout << linear_search(a, b[i]) << ' ';
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
