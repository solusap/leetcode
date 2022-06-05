#include "leetall.h"

string processOdd(unsigned long long l)
{
    string left = to_string(l);
    string t = left; 
    reverse(t.begin(), t.end());
    string ret = left + t.substr(1, t.length() - 1);
    return ret;
}

string processEven(unsigned long long r)
{
    string right = to_string(r);
    string t = right; 
    reverse(t.begin(), t.end());
    string ret = right + t;
    return ret;
}

string nearestPalindromic(string n) 
{
    unsigned long long num = stoull(n);
    if (num >= 2 && num <= 8) {
        return to_string(num - 1);
    } else if (num == 1) {
        return "0";
    } else if (num == 9) {
        return "8";
    }
    int len = n.length();
    bool ifOdd = len % 2 == 1;
    int half = ifOdd ? len / 2 + 1 : len / 2;
    vector<unsigned long long> member;
    string left = n.substr(0, half);
    unsigned long long l0 = stoull(left);     
    unsigned long long l1 = l0 + 1;
    unsigned long long l2 = l0 - 1;

    if (ifOdd) {
        member.push_back(stoull(processOdd(l0)));
        member.push_back(stoull(processOdd(l1)));
        member.push_back(stoull(processOdd(l2)));
    } else {
        member.push_back(stoull(processEven(l0)));
        member.push_back(stoull(processEven(l1)));
        member.push_back(stoull(processEven(l2)));
    }
    member.push_back(stoull("1" + string(len - 1, '0') + '1'));
    member.push_back(stoull(string(len - 1, '9')));
    std::sort(member.begin(), member.end());
    fmt::print("mem = {}\n", member);
    unsigned long long ret = 0;
    unsigned long long diff = std::numeric_limits<unsigned long long>::max();
    for (auto m : member) {
        if (m == num) {
            continue;
        }
        auto d = m > num ? m - num : num - m;
        if (d < diff) {
            diff = d;
            ret = m;
        }
    }
    return to_string(ret);
}

void test()
{
    string t = "77";
    auto ret = nearestPalindromic(t);
    fmt::print("ret = {}\n", t);
}

int main()
{
    test();
}