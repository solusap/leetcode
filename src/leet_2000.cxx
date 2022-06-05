#include "leetall.h"

string reversePrefix(string word, char ch) {
    int idx = 0;
    int len =  word.length();
    while(idx != len) {
        if (word[idx] == ch) {
            break;
        }
        idx++;
    }
    if (idx == len || idx == 0) {
        return word;
    }
    int start = 0;
    fmt::print("start = {}, end = {}", start, idx);
    while (start < idx) {
        std::swap(word[start], word[idx]);
        start++;
        idx--;
    }
    return word;
}

void test()
{
    string s = "abcdefd";
    auto r = reversePrefix(s, 'd');
    fmt::print("ret = {} \n", r);
}

int main()
{
    test();
    return 0;
}