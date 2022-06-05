#include "leetall.h"
int singleNonDuplicate(vector<int>& nums) 
{
    int len = nums.size();
    int start = 0;
    int end = len - 1;
    if (nums[0] != nums[1]) {
        return nums[0];
    }
    if (nums[len - 2] != nums[len - 1]) {
        return nums[len - 1];
    }
    while (start != end) {
        int mid = start + (end - start) / 2;
        fmt::print("start = {}, end = {}, mid = {}\n", start, end, mid);
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
        } else if(nums[mid - 1] != nums[mid]) {
            if (mid % 2 == 0) {
                start = mid;
            } else {
                end = mid;
            }
        } else if (nums[mid + 1] != nums[mid]) {
            if (mid % 2 == 0) {
                end = mid;
            } else {
                start = mid;
            }
        }
    }
    return nums[start];
}

void test0()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int ret = singleNonDuplicate(nums);
    fmt::print("ret = {}\n", ret);
}

void test1()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    int ret = singleNonDuplicate(nums);
    fmt::print("ret = {}\n", ret);
}



int main()
{
    test0();
}
