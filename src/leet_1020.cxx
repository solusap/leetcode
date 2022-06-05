#include "leetall.h"

void dfs(const vector<vector<int>>& grid, vector<vector<int>>& reached, int x, int y)
{
    int m = grid.size();
    int n = (m == 0 ? 0 : grid[0].size());
    if (x < 0 || x >= m || y < 0 || y >= n || reached[x][y] == 1 || grid[x][y] == 0) {
        return;
    }
    reached[x][y] = 1;
    dfs(grid, reached, x + 1, y);
    dfs(grid, reached, x - 1, y);
    dfs(grid, reached, x, y + 1);
    dfs(grid, reached, x, y - 1);
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = m == 0 ? 0 : grid[0].size();
    if (m == 0 || n == 0) {
        return 0;
    }
    vector<vector<int>> reach(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        dfs(grid, reach, i, 0);
        dfs(grid, reach, i, n - 1);
    }
    for (int j = 1; j < n - 1; j++) {
        dfs(grid, reach, 0, j);
        dfs(grid, reach, m - 1, j);
    }
    int ret = 0;
    fmt::print("{}\n", reach);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (reach[i][j] == 0 && grid[i][j] == 1) {
                ret += 1;
            }
        }
    }
    return ret;
}

void test()
{
	vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0 }, {0,1,1,0}, {0,0,0,0}};
    fmt::print("{}\n", grid);
    int r = numEnclaves(grid);
    fmt::print("ret = {}", r);
}

void test1()
{
	vector<vector<int>> grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    fmt::print("{}\n", grid);
    int r = numEnclaves(grid);
    fmt::print("ret = {}", r);
}


int main()
{
    test1();
}