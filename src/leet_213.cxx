#include "leetall.h"

    int robn(const vector<int>& nums, int start, int end)
    {
        int len = end - start + 1;
        vector<int> dp(len, 0);
        dp[0] = nums[start];
        if (len == 2) {
            return std::max(nums[start], nums[end]);
        }
        dp[1] = std::max(nums[start], nums[start + 1]);
        for (int i = 2; i < len; i++) {
            int y = dp[i - 2] + nums[i + start];
            int n = dp[i - 1];
            dp[i] = std::max(y, n);
        }
        fmt::print("dp = {} \n", dp);
        return dp[len - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return std::max(nums[0], nums[1]);
        }
        return std::max(robn(nums, 0, n - 2), robn(nums, 1, n - 1));
    }

int main()
{
    vector<int> nums = {1, 3, 1, 3, 100};
    int t = rob(nums);
    fmt::print("t = {}\n", t);
}