#include "leetall.h"

/// 多重背包问题

// 有 N种物品和一个容量为 C的背包，每种物品「数量有限」。
// 第i件物品的体积是w[i]，价值是v[i]，数量为s[i]。
// 问选择哪些物品，每件物品选择多少件，可使得总价值最大。
// 其实就是在 0-1 背包问题的基础上，增加了每件物品可以选择「有限次数」的特点（在容量允许的情况下）。

int multiPack(int C, int N, const vector<int>& w, const vector<int>& v, const vector<int>& s)
{
    // dp[i][j] 遍历到第i个元素的时候，总体积为j时候的最大价值
    vector<vector<int>> dp(N, vector<int>(C + 1, 0));

    for (int j = 0; j <= C; j++) {
        int k = j / v[0]; 
        int t = k > s[0] ? s[0] : k;
        dp[0][j] = t * w[0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= C; j++) {
            for (int k = 0; k <= s[i]; k++) {
                int y = 0;
                int n = 0;
                if (j - k * v[i] >= 0) {
                    y = std::max(y, dp[i - 1][j - k * v[i]] + k * w[i]);
                } else {
                    n = dp[i - 1][j];
                }
                dp[i][j] = std::max(y, n);
            }
        }
    }
    return dp[N - 1][C];
}


int multiPackRoll(int C, int N, const vector<int>& w, const vector<int>& v, const vector<int>& s)
{
    // dp[i][j] 遍历到第i个元素的时候，总体积为j时候的最大价值
    vector<vector<int>> dp(2, vector<int>(C + 1, 0));

    for (int j = 0; j <= C; j++) {
        int k = j / v[0]; 
        int t = k > s[0] ? s[0] : k;
        dp[0][j] = t * w[0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= C; j++) {
            for (int k = 0; k <= s[i]; k++) {
                int y = 0;
                int n = 0;
                if (j - k * v[i] >= 0) {
                    y = std::max(y, dp[(i - 1) & 1][j - k * v[i]] + k * w[i]);
                } else {
                    n = dp[(i - 1) & 1][j];
                }
                dp[i & 1][j] = std::max(y, n);
            }
        }
    }
    return dp[(N - 1) & 1][C];
}

int multiPackOneDim(int C, int N, const vector<int>& w, const vector<int>& v, const vector<int>& s)
{
    // dp[i][j] 遍历到第i个元素的时候，总体积为j时候的最大价值
    vector<int> dp(C + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = C; j >= 0; j--) {
            for (int k = 0; k <= s[i] && (j - k * v[i]) >= 0; k++) {
                dp[j] = std::max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }
    return dp[C];
}


int multiPackBinary(int C, int N, const vector<int>& w, const vector<int>& v, const vector<int>& s)
{
    vector<int> newW;
    vector<int> newV;
    for (int i = 0; i < N; i++) {
        int val = s[i]; // ith object total num;
        // 扁平化, 通过指数增长的方式（相当于二进制 编码）
        for (int k = 1; k <= val; k *= 2) {
            val -= k;
            newW.push_back(k * w[i]);
            newV.push_back(k * v[i]);
        }
        if (val > 0) {
            newW.push_back(val * w[i]);
            newV.push_back(val * v[i]);
        }
    }
    int nN = newW.size();
    vector<int> dp(C + 1, 0);
    for (int i = 0; i < nN; i++) {
        for (int j = C; j >= newV[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - newV[i]] + newW[i]);
        }
    }
    return dp[C];
}

template <typename T>
void testT(T f)
{
    int N = 2, C = 5;
    vector<int> v = {1, 2};
    vector<int> w = {1, 2};
    vector<int> s = {2, 1};
    int r = f(C, N, w, v, s);
    fmt::print("r = {}", r);
}


int main()
{
    testT(multiPackBinary);
    // testT(multiPackBinary);
    // testT(multiPackBinary);
    // testT(multiPackBinary);
    return 0;
}