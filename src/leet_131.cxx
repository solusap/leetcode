#include "leetall.h"

void dfs(const string& s, int i, const vector<vector<int>>& dp, vector<string>& part, vector<vector<string>>& allPart)
{
    if (i == s.length()) {
        allPart.push_back(part);
        return;
    }
    for (int j = i; j < s.length(); j++) {
        if (dp[i][j] == 1) {
            part.push_back(s.substr(i, j - i + 1));
            dfs(s, j + 1, dp, part, allPart);
            part.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 1));
    dp[0][0] = 1;
    for (int i = n -1; i>= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]) ;
        }
    }
    fmt::print("dp {}\n", dp);

    vector<string> part;
    vector<vector<string>> allPart;
    dfs(s, 0, dp, part, allPart);
    return allPart;
}

void test()
{
    string s = "aab";
    auto r = partition(s);
    fmt::print("r {}\n", r);
}

int main()
{
    test();
}