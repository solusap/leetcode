#include "leetall.h"

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    vector<string> r(numRows, "");
    int t = 2 * numRows - 2;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        int row = (i % t);  // 所处的行数
        if (row > (numRows - 1)) {
            row = t - row;
        }        
        r[row] += s[i];
    }
    string ret = "";
    for (auto str : r) {
        ret += str;
    }
    return ret;
}

void test()
{
    string s = "PAYPALISHIRING";
    int row = 4;
    auto ret = convert(s, row);
    fmt::print("ret = {}\nans = PINALSIGYAHRPI\n", ret);
}

int main()
{
    test();
    return 0;
}