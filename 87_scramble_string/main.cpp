#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <algorithm>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

using namespace std;

// "great" -> "rg tae"
//　假定没有重复,　实际上有重复，那么根据`char`来标记位置就行不通了
bool isScramble(string s1, string s2)
{
    if(s1.size() != s2.size()) return false;
    if(s1 == s2) return true;

    // 统计字符出现次数是否相等
    int sz = s1.size();
    std::vector<int> vec(26, 0);
    for(auto c : s1) ++vec[c-'a'];
    for(auto c : s2) if(--vec[c-'a']<0) return false;

    for(int i=1; i<sz; ++i) {
        std::string s11 = s1.substr(0, i);
        std::string s12 = s1.substr(i);

        std::string s21 = s2.substr(0, i);
        std::string s22 = s2.substr(i);
        std::string s21_ = s2.substr(0, sz-i);
        std::string s22_ = s2.substr(sz-i);

        // 只可以切在两个地方
        if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
        if(isScramble(s11, s22_) && isScramble(s12, s21_)) return true;
    }

    return false;
}

// TEST1
/*
int main()
{
    assert(isScramble("great", "rgtae"));
    assert(isScramble("abb", "bab"));
}
 */

// CATCH
TEST_CASE("", "")
{
    REQUIRE(isScramble("great", "rgtae"));
    REQUIRE(isScramble("abb", "bab"));
    REQUIRE(isScramble("abb1", "bab"));
}

