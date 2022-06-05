#include "leetall.h`"

// https://leetcode.cn/problems/peak-index-in-a-mountain-array/submissions/
/*
    lower_bound 
    mid == target ->  mid < mid + 1
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int first = 0;
        int last = arr.size();

        while (first < last) {
            int mid = first + (last - first) / 2;
            if (arr[mid] < arr[mid + 1]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first;
    }
};