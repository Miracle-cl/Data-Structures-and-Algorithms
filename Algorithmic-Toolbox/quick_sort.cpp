#include <iostream>
#include <vector>

using std::vector;
using std::pair;

class QuickSortP2 {
public:
    void quickSortP2(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int rand_id = std::rand() % (right - left) + left;
        std::swap(nums[left], nums[rand_id]);
        int mid = two_part(nums, left, right);

        quickSortP2(nums, left, mid-1);
        quickSortP2(nums, mid+1, right);
    }

    int two_part(vector<int>& nums, int left, int right) {
        int x = nums[left], j = left;
        for (int i = left+1; i <= right; i++) {
            if (nums[i] < x) {
                j++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[left], nums[j]);
        return j;
    }
};

class QuickSortP3 {
public:
    void quickSortP3(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int rand_id = std::rand() % (right - left) + left;
        std::swap(nums[left], nums[rand_id]);
        pair<int,int> mid = three_part(nums, left, right);

        quickSortP3(nums, left, mid.first-1);
        quickSortP3(nums, mid.second+1, right);
    }

    pair<int,int> three_part(vector<int>& nums, int left, int right) {
        int x = nums[left];
        int i = left + 1;
        // pair<int,int> tp;
        // tp = std::make_pair(left, right);
        pair<int,int> tp (left, right);
        while (i <= tp.second) {
            if (nums[i] < x) {
                std::swap(nums[tp.first], nums[i]);
                tp.first++;
                i++;
            }
            else if (nums[i] == x) {
                i++;
            }
            else {
                std::swap(nums[tp.second], nums[i]);
                tp.second--;
            }
        }
        return tp;
    }
};

int main()
{
    // std::vector<int> nums {3,2,8,1,7,4,9,5,6};
    // std::vector<int> nums {3,3,2,1,1,2,2,1,3};
    // std::vector<int> nums {3,3,2,2,1,1,1};
    std::vector<int> nums {6, 6, 0, 4, 8, 7, 6, 4, 7, 5};
    int part = 3;

    if (part == 2) {
        QuickSortP2 qsp2;
        qsp2.quickSortP2(nums, 0, nums.size() - 1);
    }
    else {
        QuickSortP3 qsp3;
        qsp3.quickSortP3(nums, 0, nums.size() - 1);
    }

    for (auto n: nums)
        std::cout << n << " ";
    std::cout << "\n";
    return 0;
}
