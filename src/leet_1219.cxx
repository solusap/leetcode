#include "leetall.h"

int getMaxGoldStartAtij(const vector<vector<int>>& grid, int x, int y, vector<vector<int>>& reached) 
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
        return 0;
    }
    if (grid[x][y] == 0 || reached[x][y] == 1) {
        return 0;
    }

    reached[x][y] = 1;

    int t1 = getMaxGoldStartAtij(grid, x + 1, y, reached) + grid[x][y];
    int t4 = getMaxGoldStartAtij(grid, x - 1, y, reached) + grid[x][y]; 
    int t2 = getMaxGoldStartAtij(grid, x, y + 1, reached) + grid[x][y];
    int t3 = getMaxGoldStartAtij(grid, x, y - 1, reached) + grid[x][y];
    reached[x][y] = 0;
    return std::max({t1, t2, t3, t4});     
}


int getMaximumGold(vector<vector<int>>& grid)
{
    int max = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            vector<vector<int>> reached(grid.size(), vector<int>(grid[0].size(), 0));
            if (grid[i][j] != 0) {
                int t = getMaxGoldStartAtij(grid, i, j, reached);
                max = max < t ? t : max;
            }
        }
    }
    return max;
}

void test0()
{
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    int r = getMaximumGold(grid);
    fmt::print("ret = {}\n", r);
}

void test1()
{
    vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    int r = getMaximumGold(grid);
    fmt::print("ret = {}\n", r);
}

void test2()
{
    vector<vector<int>> grid(10, vector<int>(10, 0));
    int r = getMaximumGold(grid);
    fmt::print("ret = {}\n", r);
}

int main()
{
    test2();
}