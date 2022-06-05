#include "leetall.h"

vector<int> getRow(int rowIndex) {
    vector<vector<int>> dp(2, vector<int>(rowIndex + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = 0;j <= i; j++) {
            if (j == 0) {
                dp[i & 1][j] = dp[(i - 1) & 1][j];
            } else {
                dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1] ;
            }
        } 
    }
    // fmt::print("dp = {}\n", dp);
    return dp[rowIndex & 1];
}

void test()
{
    for (int i = 0; i <= 4; i++) {
        auto r = getRow(i);
        fmt::print("ret = {}\n", r);
    }
}

int main()
{
    test();
}