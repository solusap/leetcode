#include "leetall.h"
#include <numeric>

bool makeSquareDfs(vector<int>& matchsticks, int edgeNo, vector<int>& marked, int curLen, int edgeLen, int used, bool& res)
{
    bool ret = false;
    fmt::print("marked = {} curLen = {}, edgeNo = {}, edgeLen = {} used = {}\n", marked, curLen, edgeNo, edgeLen, used);
    if (res == true) {
        return true;
    }
    if (used == matchsticks.size()) {
        if (edgeNo == 3) {
            fmt::print("this is the case\n");
            res = true;
            return true;
        } else {
            return false;
        }
    }

    for (int i = matchsticks.size() - 1; i >= 0; i--) {
        if (marked[i] == 1 || curLen + matchsticks[i] > edgeLen) {
            continue;
        }
        marked[i] = 1;
        if (curLen + matchsticks[i] == edgeLen) {
            ret |=  makeSquareDfs(matchsticks, edgeNo + 1, marked, 0, edgeLen, used + 1, res);
        } else {
            ret |=  makeSquareDfs(matchsticks, edgeNo, marked, curLen + matchsticks[i], edgeLen, used + 1, res);
        }
        marked[i] = 0;
    }
    return ret;
}

bool makesquaredp(vector<int>& matchsticks, int edgeLen)
{
    int n = matchsticks.size();
    vector<int> dp (1<<n, -1);
    dp[0] = 0;
    for (unsigned int i = 1; i < 1<<n; i++) {
        for (int k = 0; k < n; k++) {
            if ((i & (1 << k)) == 0) {
                continue;
            }
            unsigned int s1 = i & (~(1 << k));
            if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= edgeLen) {
                dp[i] = (dp[s1] + matchsticks[k]) % edgeLen;
                break;
            }
        }
    }
    return dp[(1<<n) - 1] == 0;
}

bool makesquare(vector<int>& matchsticks)
{
    int sum = 0;
    sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    std::sort(matchsticks.begin(), matchsticks.end());
    fmt::print("sum = {}", sum);
    if (sum % 4 != 0) {
        return false;
    }

    int edgeLen = sum / 4;
    
    for (int i = 0; i < matchsticks.size(); i++) {
        if (matchsticks[i] > edgeLen) {
            return false;
        }  
    }
    // bool ret = false;
    return makesquaredp(matchsticks, edgeLen);
    // for (int i = 0; i < matchsticks.size(); i++) {
    //     vector<int> marked(matchsticks.size(), 0);
    //     marked[i] = 1;
    //     fmt::print("--------------------------------------------------------------\n");
    //     ret |= makeSquareDfs(matchsticks, 0, marked, matchsticks[i], edgeLen, 1); 
    //     marked[i] = 0;   
    // }
    // return ret;
    // vector<int> marked(matchsticks.size(), 0);
    // return makeSquareDfs(matchsticks, 0, marked, 0, edgeLen, 0, ret);
}

void test()
{
    vector<int> matchsticks = {2,2,2,1, 1};
    bool ret = makesquare(matchsticks);
    fmt::print("ret = {}\n", ret);
}

void test1()
{
    vector<int> matchsticks = {3, 3, 3, 4};
    bool ret = makesquare(matchsticks);
    fmt::print("ret = {}\n", ret);
}

void test2()
{
    vector<int> matchsticks = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    bool ret = makesquare(matchsticks);
    fmt::print("ret = {}\n", ret);
}

void test3()
{
    vector<int> matchsticks = {5,5,5,5,16,4,4,4,4,4,3,3,3,3,4};
    bool ret = makesquare(matchsticks);
    fmt::print("ret = {}\n", ret);
}

int main()
{
    test2();
    return 0;
}