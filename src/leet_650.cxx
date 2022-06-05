#include "leetall.h"

int dfs(int cur, int copyed, int target)
{
    if (cur == target) {
        return 0;
    }
    if (cur > target) {
        return -1;
    }
    fmt::print("{} {} {} \n", cur, copyed, target);
    int copy = 0;
    int paste = 0;
    if (copyed != cur) {
        copy = dfs(cur, cur, target) + 1;       // 当前走copy 
    }
    paste = dfs(cur + copyed, copyed, target) + 1;   // 当前走paste

    if (copy > 0 && paste > 0) {
        return std::min(copy, paste);
    } else if (paste > 0) {
        return paste;
    } else if (copy > 0) {
        return copy;
    } else {
        return -1;
    }

}

int minSteps(int n) {
    
    return dfs(1, 1, n) + 1;
}

void test()
{
    int t = minSteps(836);
    fmt::print("t = {}\n", t);
}

int main()
{
    test();
}