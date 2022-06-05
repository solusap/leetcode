#include "leetall.h"

class Solution {
int binarySearchLower(const vector<int>&pos, int target) 
{
    int begin = 0;
    int len = pos.size();
    int end = len;
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (pos[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return begin;
}
public:
vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> pos;
        int len = s.length();
        vector<int> nums(len + 1, 0);

        for (int i = 0; i < len; i++) {
            if (s[i] == '|') {
                pos.push_back(i);
            }
        }
        for (int i = 1; i <= len; i++) {
            nums[i] = nums[i - 1] + (s[i - 1] == '*' ? 1 : 0);
        }
        vector<int> ret(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            int p1 = binarySearchLower(pos, q[1]);
            if (p1 == pos.size()) {
                p1 = pos.size() - 1;
            }
            if (p1 < 0 || p1 >= pos.size() || pos[p1] < q[0]) {
                continue;
            }
            int p2 = binarySearchLower(pos, q[0]);

            if (p2 < 0 || p2 >= pos.size() || pos[p2] > q[1]) {
                continue;
            }
            if (pos[p1] > q[1]) p1 -= 1;
            if (pos[p1] >= pos[p2]) {
                
                ret[i] = nums[pos[p1]] - nums[pos[p2]];
            }
        }
        return ret;
    }
};


int binarySearchLower(const vector<int>&pos, int target) 
{
    int begin = 0;
    int len = pos.size();
    int end = len;
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (pos[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return begin;
}

int binarySearchUpper(const vector<int>&pos, int target) 
{
    int begin = 0;
    int len = pos.size();
    int end = len;
    while (begin < end) {
        int mid = end - (end - begin) / 2;
        if (!(pos[mid] < target)) {
            end = mid -1;
        } else {
            begin = mid;
        }
    }
    if (begin >= len) {
        begin = len - 1;
    }
    return begin ;
}

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> pos;
        int len = s.length();
        vector<int> nums(len + 1, 0);

        for (int i = 0; i < len; i++) {
            if (s[i] == '|') {
                pos.push_back(i);
            }
        }
        fmt::print("pos = {}\n", pos);
        for (int i = 1; i <= len; i++) {
            nums[i] = nums[i - 1] + (s[i - 1] == '*' ? 1 : 0);
        }
        vector<int> ret(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            int p1 = binarySearchUpper(pos, q[1]);
            fmt::print("p1 = {}\n", p1);
            fmt::print("pos = {} , size = {}\n", pos[p1], pos.size());
            if (p1 < 0 || p1 >= pos.size() || pos[p1] < q[0]) {
                continue;
            }
            int p2 = binarySearchLower(pos, q[0]);
            fmt::print(" p2 = {}\n", p2);

            if (p2 < 0 || p2 >= pos.size() || pos[p2] > q[1]) {
                continue;
            }
            if (pos[p1] >= pos[p2]) {
                ret[i] = nums[pos[p1]] - nums[pos[p2]];
            }
        }
        return ret;
    }
void test_bs()
{
    vector<int> v = {3, 6, 12, 15, 16, 19};
    int t = 17;
    int r = binarySearchLower(v, t);
    fmt::print("r = {}\n", r);
}


void test()
{
    string s = "**|**|***|";
    vector<vector<int>> query = {{2, 5}, {5, 9}};
    auto r = platesBetweenCandles(s, query);
    fmt::print("ret = {}\n", r);
}

void test3()
{
    string s = "*|*||||**|||||||*||*||*||**|*|*||*";
    vector<vector<int>> query {{2, 33}};
    auto r = platesBetweenCandles(s, query);
    fmt::print("ret = {}\n", r);

}

void test1()
{
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> query = {{1,17},{4,5},{14,17},{5,11},{15,16}};
    auto r = platesBetweenCandles(s, query);
    fmt::print("ret = {}\n", r);
}


int main()
{
    test();
}