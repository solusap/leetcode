#include "leetall.h"

bool IsValidIpV4(string queryIP)
{
    int start = 0;
    int end = 0;
    int len = queryIP.length();
    int count = 0;
    if (len > 15 || len < 7) {
        return false;
    }
    while(start <= end && start < len && end < len) {
        if (queryIP[end] == '.' || end == len - 1) {
            if (queryIP[end] == '.') {
                count++;
            }
            if (end == len - 1) {
                end = len;
            } 
            int tLen = end - start;
            if (tLen == 0 || tLen > 3) {
                return false;
            }
            string tmp = queryIP.substr(start, tLen);
            // fmt::print("{} " , tmp);
            if (tLen != 1 && tmp[0] == '0') {
                return false;
            }
            if (std::stoi(tmp) > 255) {
                return false;
            }
            start = end + 1;
            
        } else if (queryIP[end] < '0' || queryIP[end] > '9') {
            return false;
        }
        end += 1;
    }
    if (count != 3) {
        return false;
    }
    return true;
}

bool IsValidIpV6(string queryIP)
{
    int start = 0;
    int end = 0;
    int len = queryIP.length();
    int count = 0;
    if (len > 39) {
        return false;
    }

    auto isValidHex = [](char c) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')) {
            return true;
        }
        return false;
    };
    while(start <= end && start < len && end < len) {
        int tLen = end - start;
        if (queryIP[end] == ':' || end == len -1) {
            if (queryIP[end] == ':')  {
                count++;
            }
            if (end == len - 1) {
                end = len;
            }
            if (tLen == 0 || tLen > 4) {
                return false;
            }
            string tmp = queryIP.substr(start, tLen);
            fmt::print("start = {} end = {}, tLen = {}, tmp = {} count = {}\n", start, end, tLen, tmp, count);
            start = end + 1;
        } else if (!isValidHex(queryIP[end])) {
            return false;
        }
        end += 1;
    }
    if (count != 7) {
        return false;
    }
    return true;
}

string validIPAddress(string queryIP) 
{
    if (IsValidIpV4(queryIP)) {
        return "IPv4";
    } else if (IsValidIpV6(queryIP)) {
        return "IPv6";
    } else {
        return "Neither";
    }
}



void test1()
{
    fmt::print("{}\n", IsValidIpV4("1.1.1.1"));

    fmt::print("{}\n", IsValidIpV4("1.1.1.01"));
}

void test2()
{
    // fmt::print("{}\n", IsValidIpV6("2001:0db8:85a3:0:0:8A2E:0370:7334"));

    // fmt::print("{}\n", IsValidIpV6("20x1:0db8:85a3:0:0:8A2E:0370:7334"));

    // fmt::print("{}\n", IsValidIpV6("20f1:0db8:85a3:0:0:8A2E:0370:7334"));
    // fmt::print("{}\n", IsValidIpV6("20x1:0:85a3:0:0:8A2E:0370:0:0"));
    // fmt::print("{}\n", IsValidIpV6(":20x1:0:85a3:0:0:8A2E:0370:0"));

    // fmt::print("{}\n", IsValidIpV6("2001::0db8:85a3:0:0:8A2E:0370:7334"));

    fmt::print("{}\n", IsValidIpV6("2001:0db8:85a3:0:0:8A2E:0370:73341"));
}

int main()
{
    test2();
}