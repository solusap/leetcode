#include "leetall.h"

int coinChange(vector<int>& coins, int amount)
{
    const int intmax = 0x3f3f3f3f;
    int N = coins.size();
    vector<int> dp(amount + 1, intmax);

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        // int t = coins[i];
        for (int j = 1; j <= amount; j++) {
            int y = j >= coins[i] ? dp[j - coins[i]] + 1 : intmax;
            dp[j] = std::min(y, dp[j]);
        }
    }
    return dp[amount] >= intmax ? -1 : dp[amount];
}

void test1()
{
    vector<int> coins = {1, 2, 5};
    int amount = 12;
    int num = coinChange(coins, amount);
    cout<<"num = " << num << endl;
}

void test2()
{
    vector<int> coins = {2};
    int amount = 3;
    int num = coinChange(coins, amount);
    cout<<"num = " << num << endl;
}

void test3()
{
    vector<int> coins = {1};
    int amount = 2;
    int num = coinChange(coins, amount);
    cout<<"num = " << num << endl;
}

int main()
{
    test3();
}