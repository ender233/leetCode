#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

/*
 * Algorithm: std::string pop_back
 * Note: check whether there still be some work to do after finishing 
 */

void reverseWords(string &s)
{
    std::vector<string> res;
    std::string tmp("");
    for(auto c : s) {
        if(c != ' ') tmp += c;
        else if(!tmp.empty()) {
            res.push_back(tmp);
            tmp.clear();
        }
    }
    if(!tmp.empty()) res.push_back(tmp);

    s.clear();
    for_each(res.rbegin(), res.rend(), [&](std::string resStr){
                s += resStr + " ";
            });
    s.pop_back();
}

TEST_CASE("", "")
{
    std::string s1(" the sky is blue");
    std::string res1("blue is sky the");
    reverseWords(s1);
    
    REQUIRE(s1 == res1);
}
