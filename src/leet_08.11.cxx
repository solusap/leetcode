#include "leetall.h"

int waysToChange(int n) 
{
    vector<int> v = {1, 5, 10, 25};
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = v[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - v[i]]) % 1000000007;
        }
    }
    return dp[n];
}

void test()
{
    int n = 10;
    int r = waysToChange(n);
    fmt::print(" r = {}\n", r);
}

int main()
{
    test();
    return 0;
}