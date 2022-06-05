#include "leetall.h"

// 给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。
// 斐波那契数字定义为：
// F1 = 1
// F2 = 1
// Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
// 数据保证对于给定的 k ，一定能找到可行解。
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 思路，完全dp问题，首先找到到 小于k的所有dp
// const int INTMAX = 1e9 + 1;


void print_intvec(const vector<int>& ivec)
{
    for (auto& i : ivec) {
        cout<<i<<" ";
    }
    cout<<endl;
}

vector<int> GetFibList(int k)
{
    vector<int> ret = {1, 2};
    for(;;) {
        int t = *(ret.rbegin()) + *(ret.rbegin() + 1);
        if (t > k) {
            break;
        }
        ret.push_back(t);
    }
    return ret;
}

int findMinFibonacciNumbers(int k) 
{
    const int INTMAX = 1000000001;
    vector<int> fib = GetFibList(k);
    int N = fib.size();
    fmt::print("{}\n", fib);
    // dp[i][j] 遍历到第i个数字时，和为j, 使用到的数字数量的最小值
    vector<int> dp(k + 1, INTMAX);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= k; j++) {
            int y = j >= fib[i] ? dp[j - fib[i]] + 1 : INTMAX;
            dp[j] = std::min(dp[j], y);
        }
        fmt::print("======== {}th iterator=======", i);
        fmt::print("{}\n", dp);        
    }
    return dp[k];
}

int dfs(const vector<int>& fib, int k, int idx)
{
    if (k == 0) {
        return 0;
    }
    
    fmt::print("k = {}, idx = {}\n", k, idx);
    // find idx
    if (fib[idx] > k) {
        while (idx > 0) {
            if (fib[idx] <= k) {
                break;
            }
            idx--;
        }
    }
    return dfs(fib, k - fib[idx], idx) + 1;    
}

int findMinFibonacciNumbersDfs(int k) 
{
    vector<int> fib = GetFibList(k);
    fmt::print("{}\n", fib);
    return dfs(fib, k, fib.size() - 1);
}


void test0()
{
    int k = 2;
    int r = findMinFibonacciNumbers(k);
    cout<<r<<endl;
}

void test1()
{
    int k = 7;
    int r = findMinFibonacciNumbers(k);
    cout<<r<<endl;
}

void test2()
{
    int k = 9083494;
    int r = findMinFibonacciNumbersDfs(k);
    fmt::print(" ret = {}", r);
}

int main()
{
    test2();
}