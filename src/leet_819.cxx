#include "leet_all.h"

// split string with ohter character
vector<string_view> split(string_view strv)
{
    vector<string_view> ret;
    size_t start = 0;
    size_t len = strv.size();

    while(start != len) {
        size_t next = start;
        while (next < len) {
            if ((strv[next] > 'a' && strv[next] < 'b' || (strv[next] > 'A' && strv[next] < 'Z')) {
                next++;
            } else {
                if (next != start) {
                    ret.emplace_back(strv.substr(start, next - start));
                }
            }
        }
    }
}