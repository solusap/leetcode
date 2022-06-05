#include "leetall.h"
#include <fmt/core.h>

int lower_bound(vector<int>& nums, int target)
{
    int first = 0;
    int last = nums.size();

    while (first < last) {
        int mid = first + (last - first) / 2;
        if (nums[mid] < target) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return first;
}

int searchInsert(vector<int>& nums, int target) {
    auto it = lower_bound(nums, target);
    return it;
}

void test()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 8;
    fmt::print("{} \n", searchInsert(nums, target));
}

int main()
{
    test();
    return 0;
}