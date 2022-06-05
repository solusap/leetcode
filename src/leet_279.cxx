#include "leetall.h"

int numSquares(int n) 
{
    // int cap = n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        int t = std::floor(std::sqrt(i));
        if (t * t == i) {
            v.push_back(i);
        }
    }
    int N = v.size();

    for (int i = 0; i < N; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
    // dp[i][j] 遍历到第i个质因子时, 和为j的时候，使用的最小的数字数量
    //  dp[i][j] = min {dp[i1][j - k * v[i]] + k}
    // 
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        int x = v[i];
        for (int j = x; j <= n; j++) {
            dp[j] = std::min(dp[j], dp[j - x] + 1);
        }
    }
    return dp[n];
}

void test1()
{
    int r = numSquares(12);
    cout<<"r = "<<r<<"\n";
}

void test2()
{
    int r = numSquares(1);
    cout<<"r = "<<r<<"\n";
}

int main()
{
    test2();
}