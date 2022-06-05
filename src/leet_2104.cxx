#include <leetall.h>

long long subArrayRanges(vector<int>& nums) {
    int len = nums.size();
    long long ret = 0;

    // 对从i 开始，长度从 2 到 len - 2 - (i + 1) 的区间，更新其最大值和最小值
    for (int i = 0; i < len; i++) {
        deque<int> tmax;
        deque<int> tmin;
        for (int f = 0; f < len - i; f++) {
            // while (!tmax.empty() && tmax.front() < i) {
            //     tmax.pop_front();
            // }
            while (!tmax.empty() && nums[i + f] > nums[tmax.back()]) {
                tmax.pop_back();
            }
            tmax.push_back(i + f);

            // while (!tmin.empty() && tmin.front() < i) {
            //     tmin.pop_front();
            // }
            while (!tmin.empty() && nums[i + f] < nums[tmin.back()]) {
                tmin.pop_back();
            }
            tmin.push_back(i + f);
            long long t = (long long)(nums[tmax.front()] - nums[tmin.front()]);
            fmt::print("i = {}, f = {}, max = {}, min = {}\n", i, f, nums[tmax.front()], nums[tmin.front()]);
            // fmt::print("i = {}, f = {} maxq = {}, minq = {}, t = {} \n", i, f, tmax, tmin, t);
            ret += t;
        }
    }
    return ret;
}


long long subArrayRangesDp(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> dpMax(len, vector<int>(len, 0));
    vector<vector<int>> dpMin(len, vector<int>(len, 0));
    long long ret = 0;
    for (int l = 0; l < len; l++) {
        dpMax[l][l] = nums[l];
        dpMin[l][l] = nums[l];
        for (int r = l + 1; r < len; r++) {
            dpMax[l][r] = std::max(dpMax[l][r - 1], nums[r]);
            dpMin[l][r] = std::min(dpMin[l][r - 1], nums[r]);
            fmt::print("l = {}, r = {}, max = {}, min = {}\n", l, r, dpMax[l][r], dpMin[l][r]);
            ret += dpMax[l][r] - dpMin[l][r];
        }
    }
    return ret;
}

void test()
{
    vector<int> nums = {4,-2,-3,4,1};
    auto ret = subArrayRangesDp(nums);
    fmt::print("ret = {}\n", ret);
}

int main()
{
    test();
}