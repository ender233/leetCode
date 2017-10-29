#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <map>
using namespace std;

bool judgeCircle(string moves)
{
    map<char, int> mp;
    for(auto &c : moves) {
        ++mp[c]; 
    }
    
    if(mp['R'] != mp['L']) return false;
    if(mp['U'] != mp['D']) return false;
    return true;
}


TEST_CASE("", "")
{
    REQUIRE(judgeCircle(std::string("UD")));
    REQUIRE(!judgeCircle(std::string("LL")));
}
