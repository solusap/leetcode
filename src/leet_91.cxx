#include "leetall.h"

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = (s[0] == '0' ? 0 : 1);
        
        for (int i = 1; i < n; i++) {
            int t1 = s[i] == '0' ? 0 : dp[i - 1];
            int t2 = 0;
            if (s[i - 1] != '0') {
                int t = stoi(s.substr(i - 1, 2));
                if (t <= 26 && i - 2 >= 0) {
                    t2 = dp[i - 2];
                } else if (i == 1) {
                    t2 = 1;
                }
            }
            dp[i] = t1 + t2;
        }
        fmt::print("{}\n", dp);
        return dp[n - 1];
    }

void test()
{
    string s = "226";
    int r = numDecodings(s);
    fmt::print("ret = {}\n", r);
}

int main()
{
    test();
}