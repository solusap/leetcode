#include "leetall.h"

int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) 
{
    auto cmp = [](vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    };
    std::sort(tires.begin(), tires.end(), cmp);
    
    for (int i = 0; i < numLaps; i++) {

    }
}

int test()
{
    vector<vector<int>>tires = {{1,10},{2,2},{3,4}};
    int changeTime = 6, numLaps = 5;
}