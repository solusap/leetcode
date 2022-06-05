#include "leetall.h"

int GetSums(vector<int>& time, int day)
{
    int sums = 0;
    for (auto i : time) {
        sums += day / i;
    }
    return sums;
}

long long minimumTime(vector<int>& time, int totalTrips) 
{  
    std::sort(time.begin(), time.end());
    long long maxDay = totalTrips * time[0];

    using ll = long long;    
    ll start = 1;
    ll end = maxDay;
    fmt::print("start = {}, end = {}\n", start, end);
    auto mid = start + (start - end) / 2;
    while (start <= end) {
        mid = start + (end - start) / 2;
        auto sum = GetSums(time, mid);
        fmt::print("mid = {}, sum = {}\n", mid, sum);

        if (sum >= totalTrips) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start;
}


void test()
{
    vector<int> time = {1, 2, 3};
    int totalTrips = 5;
    auto ret = minimumTime(time, totalTrips);
    fmt::print("{}\n", ret);
}

void test1()
{
    vector<int> time = {5, 10, 10};
    int totalTrips = 9;
    auto ret = minimumTime(time, totalTrips);
    fmt::print("{}\n", ret);
}

void test2()
{
    vector<int> time = {2};
    int totalTrips = 1;
    auto ret = minimumTime(time, totalTrips);
    fmt::print("{}\n", ret);
}

int main()
{
    test2();
}