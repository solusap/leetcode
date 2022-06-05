#include "leetall.h"

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> ret;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        int tempmax = matrix[i][0];
        int tempidx = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > tempmax) {
                tempmax = matrix[i][j];
                tempidx = j;
            }
        }
        int tempmin = matrix[0][tempmax];
        for (int k = 0; k < m; k++) {
            if (matrix[k][tempidx] < tempmin) {
                tempmin = matrix[k][tempidx];
            }
        }
        if (tempmax == tempmin) {
            ret.push_back(tempmax);
        }
    }
    return ret;
}

void test()
{
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    auto ret = luckyNumbers(matrix);
    fmt::print("ret = {}\n", ret);
}

int main()
{
    test();
}