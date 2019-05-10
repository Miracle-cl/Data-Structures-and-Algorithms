#include <iostream>
#include <vector>

using std::vector;

class MergeSort {
public:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        // vector<int> temp(right-left, 0);
        int i = left, j = mid+1;
        
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
            temp.push_back(nums[i++]);

        while (j <= right)
            temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++)
            nums[k] = temp[k-left];
    }
};


int main()
{
    std::vector<int> v1 {3,2,8,1,7,4,9,5,6};
    int l = 0, r = v1.size() - 1;
    MergeSort ms;
    ms.mergeSort(v1, l, r);
    for (auto n: v1)
        std::cout << n << " ";
    std::cout << "\n";
    return 0;
}
