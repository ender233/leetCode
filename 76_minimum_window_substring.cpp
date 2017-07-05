#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <string>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

struct minWinsRes
{
    minWinsRes() : beg(0), end(0), curMinNum(999) {}
    int beg;
    int end;
    int curMinNum;
};

bool isSubString(const std::map<char, int> &cache)
{
    for(auto &ca : cache) {
        if(ca.second == 0) return false;
    }
    return true;
}

string minWindow(string s, string t)
{
    std::map<char, int> curCache;
    std::for_each(t.begin(), t.end(), [&](char c){
                curCache[c] = 0;
            });

    if(s.empty()) return "";
    int size = s.size();

    minWinsRes minRes;
    int beg(0), end(0);

    for(; end<size; ) {
        // ++begin
        while(beg<size && !curCache.count(s[beg])) ++beg;

        // ++end
        if(beg > end) ++end; 
        while(end<size && !isSubString(curCache)) {
            if(curCache.count(s[end])) ++curCache[s[end]];
            ++end;
        }

        // delete the first one
        while(isSubString(curCache)) {
            if(minRes.curMinNum > end-beg) {
                minRes.curMinNum = end-beg; 
                minRes.beg = beg;
                minRes.end = end;
            }

            --curCache[s[beg++]];
            while(beg<size && !curCache.count(s[beg])) ++beg;
        }
    }

    return s.substr(minRes.beg, minRes.curMinNum);
}

TEST_CASE(" ", " ")
{
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    REQUIRE(string("BANC") == minWindow(s1, t1));

    // wrong solution based on current case
    REQUIRE(string("") == minWindow(string("a"), string("aa")));
}
