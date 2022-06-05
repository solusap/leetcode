#include "leetall.h"

// N 中物品 C 是总容量  v是每种的体积， w是价值
int maxValue(int N, int C, vector<int> v, vector<int> w)
{
    // dp = max {dp[i - i][j - k * v[i]] + k * w[i]  : for k in 0..(j - k * v[i] >= 0)}
    vector<vector<int>> dp(N , vector<int>(C + 1, 0));
    for (int j = 0; j <= C; j++) {
        int max = j / v[0];
        dp[0][j] = max * w[0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= C; j++) {
            int max = -1;
            for (int k = 0; k < j - k * v[i]; k++) {
                int t = dp[i - i][j -k * v[i]] + k * w[i];
                max = max >= t ? max : t;
            }
            dp[i][j] = max;
        }
    }
    return dp[N - 1][C];
}

int maxValueOnedim(int N, int C, vector<int> v, vector<int> w)
{
    vector<int> dp(C + 1, 0);
    for (int j = 0; j <= C; j++) {
        int max = j / v[0];
        dp[j] = max * w[0];
    }    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= C; j++) {
            int max = -1;
            for (int k = 0; k < j - k * v[i]; k++) {
                int t = dp[j -k * v[i]] + k * w[i];
                max = max >= t ? max : t;
            }
            dp[j] = max;
        }
    }
    return dp[C];
}


void test1()
{
    int N = 2, C = 5;
    vector<int> v = {1, 2};
    vector<int> w = {1, 2};
    int ret = maxValue(N, C, v, w);
    cout<<ret<<endl;
}

void test2()
{
    int N = 2, C = 5;
    vector<int> v = {1, 2};
    vector<int> w = {1, 2};
    int ret = maxValueOnedim(N, C, v, w);
    cout<<ret<<endl;
}

int main()
{
    test1();
    test2();

}