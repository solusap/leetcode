#include "leetall.h"

string add(const string& s1, const string& s2)
{
    vector<int> s(std::max(s1.length(), s2.length()) + 1, 0);
    string s3(s1.rbegin(), s1.rend());
    string s4(s2.rbegin(), s2.rend());

    for (int i = 0; i < s3.length(); i++) {
        s[i] += s3[i] - '0';
    }
    for (int i = 0; i < s4.length(); i++) {
        s[i] += s4[i] - '0';
    }
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] + j;
        j = t / 10;
        s[i] = t % 10;
    }
    std::reverse(s.begin(), s.end());
    string ret;
    int start = s[0] == 0 ? 1 : 0;
    for (;start < s.size(); start++) {
        ret += s[start] + '0';
    }
    return ret;
}

bool dfs(const string& num, int idx, vector<string>& nums)
{
    fmt::print(" idx = {} nums = {}\n", idx, nums);
    if (idx >= num.length()) {
        return nums.size() >= 3;
    }
    int searchIdx = num[idx] == '0' ? idx + 1 : num.length();
    for (int end = idx; end < searchIdx; end++) {
        string t = num.substr(idx, end - idx + 1);
        if (nums.size() < 2  || add(*(nums.rbegin()), *(nums.rbegin() + 1)) == t) {
            nums.push_back(t);
            if (dfs(num, end + 1, nums)) {
                return true;
            }
            nums.pop_back();
        }
    }
    return false;
}


bool isAdditiveNumber(string num) {
    vector<string> tmp;
    bool ret = dfs(num, 0, tmp);
    return ret;
}


void test()
{
    string num = "101020305080130210";
    bool r = isAdditiveNumber(num);
    fmt::print("r = {}\n", r);
}

void test1()
{
    string num = "199100199";
    bool r = isAdditiveNumber(num);
    fmt::print("r = {}\n", r);
}

void test2()
{
    string num = "11111111111011111111111";
    bool r = isAdditiveNumber(num);
    fmt::print("r = {}\n", r);
}

void test3()
{
    string num = "10101";
    bool r = isAdditiveNumber(num);
    fmt::print("r = {}\n", r);
}

int main()
{
    // fmt::print("result = {}", add("9999999999999", "999"));
    test2();
}