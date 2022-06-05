#include "leetall.h"

    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ret;
        for (int len = n; len >= 0; len--) {
            int tmpMax = arr[0];
            int tmpId = 0;
            for (int i = 0; i < len; i++) {
                if (arr[i] > tmpMax) {
                    tmpMax = arr[i];
                    tmpId = i;
                }
            }
            if (tmpId != len - 1) {
                std::reverse(arr.begin(), arr.begin() + tmpId + 1);
                if (tmpId != 0) {
                    ret.push_back(tmpId + 1);
                }
                auto arre = arr.begin() + len;
                std::reverse(arr.begin(), arre);
                if (len != 1 && len != 0) {
                    ret.push_back(len);
                }             
            }
            
        }
        // fmt::print("arr = {}\n", arr);
        return ret;
    }

void test()
{
    vector<int> arr = {3, 2, 4, 1};
    auto ret = pancakeSort(arr);
    fmt::print("ret = {}", ret);
}


int main()
{
    test();
}

        