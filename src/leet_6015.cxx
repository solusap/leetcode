#include "leetall.h"

long long coutPairs(vector<int>& nums, int k) {
        set<int> hash;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            hash.insert(nums[i]);
            max = max > nums[i] ? max : nums[i];
        }
        int ret = 0;
        for (int j = 0; j < nums.size(); j++) {
            int n = max / k * nums[j];
            for (int t = 1; t <= n; t++) {
                int tmp = t * k / nums[j];
                if ((t * k) % nums[j] == 0) {
                    if (tmp >= nums[j] && hash.count(tmp) > 0) {
                        ret++;
                    }
                }
                
            }
        }
    return ret;
}

void test()
{
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    int ret = coutPairs(nums, k);
    fmt::print("{}\n", ret);
}

int main()
{
    test();
}