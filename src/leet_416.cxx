#include "leetall.h"

bool canPartition1(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if (sum % 2 == 1) {
        return false;
    }
    int cap = sum / 2;
    vector<vector<int>> dp(n, vector<int>(cap + 1, 0));

    for (int i = 0; i <= cap; i++) {
        dp[0][i] = i >= nums[0] ? nums[0] : 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= cap; j++) {
            int n = dp[i - 1][j];
            int y = j >= nums[i] ? dp[i - 1][j - nums[i]] + nums[i] : 0;
            if (n > y) {
                dp[i][j] = n;
            } else {
                dp[i][j] = y;
            }
        }
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n - 1][sum / 2] == sum / 2;
}

bool canPartitionUn(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if (sum % 2 == 1) {
        return false;
    }
    int cap = sum / 2; 
    // dp[i][j]  = true / false :  -> 遍历到第i个元素是, 恰好等于j的 
    vector<vector<bool>> dp(n + 1, vector<bool>(cap + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= cap; i++) {
        dp[1][i] = i == nums[0] ? true : false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            bool y = j >= nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : false;
            bool n = dp[i - 1][j];
            dp[i][j] = y || n;
        }
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][cap];
}





void test1()
{
    vector<int> nums = {1, 5, 5, 11};
    bool ret = canPartition(nums);
    cout<<ret<<endl;
}

void test2()
{
    vector<int> nums = {1, 2, 3, 5};
    bool ret = canPartition(nums);
    cout<<ret<<endl;
}

int main()
{
    test1();
    cout<<"  ----------------        "<<endl;
    test2();
    return 0;
}