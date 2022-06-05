#include "leetall.h"
#include <numeric>

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
        return false;
    }
    int partialSum = sum / k;
    int n = nums.size();

    vector<int>dp (1 << n, -1);
    dp[0] = 0;

    for (size_t s = 1; s < 1<<n; s++) {
        for (size_t t = 0; t < n; t++) {
            if ((s & (1 << t)) == 0) {
                continue;
            }
            size_t s1 = s & (~ (1 << t));
            if (dp[s1] != -1 && dp[s1] + nums[t] <= partialSum) {
                dp[s] = (dp[s1] + nums[t]) % partialSum;
                break;
            }
        }
    }
    return dp[(1 << n) - 1] == 0;
}

void test()
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    bool ret = canPartitionKSubsets(nums, k);
    fmt::print("ret = {}\n", ret);
}

int main()
{
    test();
}