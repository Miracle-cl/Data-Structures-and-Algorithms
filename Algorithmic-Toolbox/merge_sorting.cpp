#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void merge_array(vector<int> &a, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    vector<int> temp(r-l+1);
    while (i <= mid && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= r) {
        temp[k++] = a[j++];
    }

    for (int i = 0; i < k; ++i)
        a[l+i] = temp[i];
}


void merge_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    merge_sort(a, l, mid); // left was sorted
    merge_sort(a, mid+1, r); // right was sorted
    merge_array(a, l, mid, r); //merge left and right
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }

    merge_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
}
