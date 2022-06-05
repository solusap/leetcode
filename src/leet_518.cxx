#include "leetall.h"

int change(int amount, vector<int>& coins)
{
    int n = coins.size();
    vector<int>dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= amount; j++) {
            int t = j >= coins[i] ? dp[j - coins[i]] : 0;
            dp[j] += t;
        }
    }
    return dp[amount];
}

void test1()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int t = change(amount, coins);
    cout<<"t ="<<t<<endl;
}

void test2()
{
    int amount = 3;
    vector<int> coins = {2};
    int t = change(amount, coins);
    cout<<"t = "<<t<<endl;
}

int main()
{
    test1();
    test2();
}