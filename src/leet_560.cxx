#include "leetall.h"

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ret = 0;
    vector<int> sums(n + 1, 0);
    map<int, int> hash;
    hash.insert({0, 1});
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    hash.insert({0, 1});
    for (int i = 1; i <= n; i++) {
        int t = sums[i];
        int d = t - k;
        if (hash.count(d) != 0) {
            ret += hash.at(d);
        }
        hash[t] += 1;
    }
    return ret;
}

void test()
{
    vector<int> nums = {0, 1};
    int k = 0;
    int s = subarraySum(nums, k);
    fmt::print("ret = {}\n", s);
}

void test1()
{
    vector<int> nums = {-1, -1, 1};
    int k = -1;
    int s = subarraySum(nums, k);
    fmt::print("ret = {}\n", s);
}

int main()
{
    test1();
}