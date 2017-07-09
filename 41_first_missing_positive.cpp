#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    if(nums.empty()) return 1;

    set<int> s1;
    for(auto v : nums) {
        if(v<=0) continue;
        if(s1.count(v)) continue;

        s1.insert(v);
    }
    if(s1.empty()) return 1;

    int i = 1;
    for(auto s : s1) {
        if(s!=(i++)) return i-1;
    }
    return i;
}

TEST_CASE("", "")
{
    vector<int> vec0{};
    vector<int> vec1 = {1,2,0};
    vector<int> vec2 = {3,4,-1,1};
    vector<int> vec3 = {2};
    vector<int> vec4 = {1,1};
    vector<int> vec5 = {-5,1000};

    REQUIRE(3 == firstMissingPositive(vec1));
    REQUIRE(2 == firstMissingPositive(vec2));
    REQUIRE(1 == firstMissingPositive(vec0));
    REQUIRE(1 == firstMissingPositive(vec3));
    REQUIRE(2 == firstMissingPositive(vec4));
    REQUIRE(1 == firstMissingPositive(vec5));
}
