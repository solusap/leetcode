#include "leetall.h"

class NumMatrix {
    vector<vector<int>> sum;
    vector<vector<int>> matrix;
    size_t m;
    size_t n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this -> matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
        sum.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for (auto &r : sum) {
            fmt::print("{}\n", r);
        }
        
   }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = row1 >= m ? m - 1: row1;
        row2 = row2 >= m ? m - 1 : row2;
        col1 = col1 >= n ? n - 1 : col1;
        col2 = col2 >= n ? n - 1 : col2;
        int ret = sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
        fmt::print("t1 = {}, t2 = {}, t3 = {}, t4 = {}\n", 
                   sum[row2 + 1][col2 + 1],
                   sum[row2 + 1][col1],
                   sum[row1][col2 + 1],
                   sum[row1][col1]);
        return ret;
    }
};

void test()
{
    vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};

    for (auto &r : matrix) {
        fmt::print("{}\n", r);
    }
    fmt::print("--------- \n");
    NumMatrix nm(matrix);
    int ret = nm.sumRegion(0,0,5,5);
    fmt::print("ret = {}\n", ret);
}

void test1()
{
    vector<vector<int>> matrix = {{-4, -5}};

    for (auto &r : matrix) {
        fmt::print("{}\n", r);
    }
    NumMatrix nm(matrix);
    int ret = nm.sumRegion(0,0,0,1);
    fmt::print("ret = {}\n", ret);
}

int main()
{
    test1();
}