#include "leetall.h"


// i 枚举到第i个物品
// c 剩余容量
int dfs(const vector<int>& v,  const vector<int>& w, int i, int c)
{
    if (i >= v.size() || c <= 0) {
        return 0;
    }
    return std::max(
        dfs(v, w, i + 1, c - v[i]) + w[i],
        dfs(v, w, i + 1, c)
    );
}

// from dfs -> dp
int dps(const vector<int>& v,  const vector<int>& w, int C)
{
    // dp[i][j] 枚举到第i个物品，剩余容量为j时的最大价值
    // dp[i][j] = max {dp[i - 1][j], dp[i - 1][j - v[i]] + w[j]}
    int len = v.size();
    vector<vector<int>> dp(len, vector<int>(C + 1, 0));
    for (int i = 0; i <= C; i++) {
        dp[0][i] = i >= v[0] ? w[0] : 0;   // 如果剩余的容量大于 v[0], 则最大价值为w[0]
    }
    for (int i = 1; i < len; i++) {
        for (int j = 0; j <= C; j++) {
            // 不选择该物品
            int n = dp[i - 1][j];
            // 选择该物品
            int y = j >= v[i] ? dp[i - 1][j - v[i]] + w[i] : 0;
            dp[i][j] = std::max(n, y);
        }
    }
    return dp[len - 1][C];
}

int dps2(const vector<int>& v,  const vector<int>& w, int C)
{
    // dp[i][j] 枚举到第i个物品，剩余容量为j时的最大价值
    // dp[i][j] = max {dp[i - 1][j], dp[i - 1][j - v[i]] + w[j]}
    int len = v.size();
    vector<vector<int>> dp(2, vector<int>(C + 1, 0));
    for (int i = 0; i <= C; i++) {
        dp[0][i] = i >= v[0] ? w[0] : 0;   // 如果剩余的容量大于 v[0], 则最大价值为w[0]
    }
    for (int i = 1; i < len; i++) {
        for (int j = 0; j <= C; j++) {
            // 不选择该物品
            int n = dp[(i - 1) & 1][j];
            // 选择该物品
            int y = j >= v[i] ? dp[(i - 1) & 1][j - v[i]] + w[i] : 0;
            dp[i & 1][j] = std::max(n, y);
        }
    }
    return dp[(len - 1) & 1][C];
}

int dps1(const vector<int>& v,  const vector<int>& w, int C)
{
    // dp[i][j] 枚举到第i个物品，剩余容量为j时的最大价值
    // dp[j] j 为剩余容量为j的最大值
    int len = v.size();
    vector<int> dp(C + 1, 0);
    for (int i = 1; i < len; i++) {
        for (int j = C; j >= v[i]; j--) {
            // 不选择该物品
            int n = dp[j];
            // 选择该物品
            int y = dp[j - v[i]] + w[i];
            dp[j] = std::max(n, y);
        }
    }
    return dp[C];
}


int maxWeight(const vector<int>& v,  const vector<int>& w, int C)
{
    vector<vector<int>> dp(v.size(), vector<int>(C, 0));
    // dp[i][j]  选择第i件物品，且剩余j容量为j的时候的最大价值
    // int i =  dfs(v, w, 0, C);
    int j = dps1(v, w, C);
    return j;
}


int main()
{
    int C = 5;
    vector<int> v = {4, 2, 3};
    vector<int> w = {4, 2, 3};
    int r = maxWeight(v, w, C);
    cout<<"ret = " << r << endl;
    return 0;
}