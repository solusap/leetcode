#include <leetall.h>

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int len = security.size();
    if (len < 2 * time + 1) {
        return vector<int>();
    }
    vector<int> down(len + 1, 0);
    vector<int> up(len + 1, 0);

    for (int i = 1; i < len; i++) {
        if (security[i] <= security[i - 1]) {
            down[i] = down[i - 1] + 1;
        } else {
            down[i] = 0;
        }
    }
    fmt::print("down = {}\n", down);
    for (int i = len - 2; i >= 0; i --) {
        if (security[i] <= security[i + 1]) {
            up[i] = up[i + 1] + 1;
        } else {
            up[i] = 0;
        }
    }
    fmt::print("up = {}\n", up);

    vector<int> ret;
    for (int i = time; i < len - time; i++) {
        if (up[i] >= time && down[i] >= time) {
            ret.push_back(i);
        }
    }
    return ret;
}

void test()
{
    vector<int> security = {5,3,3,3,5,6,2};
    int time = 2;
    auto ret = goodDaysToRobBank(security, time);
    fmt::print("{} \n", ret);

}

int main()
{
    test();
    return 0;
}