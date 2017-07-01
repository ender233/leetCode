#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
#include <algorithm>
using namespace std;

int findkthLargest(vector<int> &nums, int k)
{
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}

TEST_CASE("", "")
{
    vector<int> vec1{3,2,1,5,6,4};
    REQUIRE(5 == findkthLargest(vec1, 2));
}
