#include <iostream>
#include <vector>

using std::vector;

long long merge_inversions(vector<int> &a, size_t left, size_t ave, size_t right) {
    int i = left;
    int j = ave + 1;
    int k = 0;
    long long number = 0;
    vector<int> b(right-left+1);
    while (i <= ave && j <= right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
            number += (ave + 1 - i);
        }
    }

    while (i <= ave) {
        b[k++] = a[i++];
    }

    while (j <= right) {
        b[k++] = a[j++];
    }

    for (int i = 0; i < k; ++i)
        a[left+i] = b[i];

    return number;
}


long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right <= left) return number_of_inversions;
    size_t ave = (left + right) / 2;
    number_of_inversions = get_number_of_inversions(a, left, ave);
    number_of_inversions += get_number_of_inversions(a, ave+1, right);
    //write your code here
    number_of_inversions += merge_inversions(a, left, ave, right);
    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    //vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, 0, a.size()-1) << '\n';
}
