#include "leetall.h"

// 返回的是必赢是否
int canIWinDfs(int maxNum, vector<vector<int>>& f, int desiredTotal, int num, int sum, int state)
{
    // 硬搜
    // f[state][num] 第num伦选择状态为state的情况，输赢状态
    // 所有数字都选完了，但是还是没有赢，返回失败
    if (state == ((1 << maxNum) - 1) && sum < desiredTotal) return -1;

    if (f[state][num % 2] != 0) {
        return f[state][num % 2]; // 该状态出现过，记忆化
    }

    int h = num % 2 == 0 ? 1 : -1;
    for (int i = 0; i < maxNum; i++) {
        // 第i个数字已经选择过了
        if (((state >> i) & 1) == 1) {
            continue; 
        }
        // 如果第i个数字满足条件，则给对应的
        if (sum + i + 1 >= desiredTotal) {
            return f[state][num % 2] = h;
        }
        if (canIWinDfs(maxNum, f, desiredTotal, num + 1, sum + i + 1,  state | 1 << i) == h) {
            return f[state][num % 2] = h;
        }
    }
    return f[state][num % 2] = -h;
}

int canIWinDfsCompress(int maxNum, vector<int>& f, int desiredTotal, int sum, int state)
{
    // 硬搜
    // f[state] 选择状态为state的情况，先手输赢状态
    // 所有数字都选完了，但是还是没有赢，返回失败
    if (state == ((1 << maxNum) - 1) && sum < desiredTotal) return -1;

    if (f[state] != 0) {
        return f[state]; // 该状态出现过，记忆化
    }

    for (int i = 0; i < maxNum; i++) {
        // 第i个数字已经选择过了
        if (((state >> i) & 1) == 1) {
            continue; 
        }
        // 如果第i个数字满足条件，则给对应的
        if (sum + i + 1 >= desiredTotal) {
            return f[state] = 1;
        }
        // 如果对面在先手状态必输，则我方必赢
        if (canIWinDfsCompress(maxNum, f, desiredTotal, sum + i + 1,  state | 1 << i) == -1) {
            return f[state] = 1;
        }
    }
    return f[state] = -1;
}


bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    // vector<vector<int>> f (1 << 20, vector<int>(2, 0));
    // if (desiredTotal == 0) {
    //     return true;
    // }
    // return canIWinDfs(maxChoosableInteger, f, desiredTotal, 0, 0, 0) == 1;
    vector<int> f(1<<20, 0);
    if (desiredTotal == 0) {
        return true;
    }
    return canIWinDfsCompress(maxChoosableInteger, f, desiredTotal, 0, 0) == 1;
}

void test()
{
    fmt::print("t1 = {}\n", canIWin(10, 11));
    fmt::print("t2 = {}\n", canIWin(10, 0));
    fmt::print("t2 = {}\n", canIWin(10, 1));
}

int main()
{
    test();
    return 0;
}

