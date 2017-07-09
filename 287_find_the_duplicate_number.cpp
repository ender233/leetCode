#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    set<int> s1;
    for(auto v : nums) {
        if(s1.count(v)) return v;
        else s1.insert(v);
    }
}

TEST_CASE("", "")
{
    std::vector<int> vec1{1,3,4,5,6,5};
    REQUIRE(5 == findDuplicate(vec1));
}
