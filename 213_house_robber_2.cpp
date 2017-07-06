#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

map<int, int> cache1;
map<int, int> cache2;

/*
 * Algorithm: DP
 */

int robhelper(int index, vector<int> &nums, int size)
{
    if(index >= size) return 0;

    if(nums[size-1] == 0 && cache2.count(index)) return cache2[index];
    if(nums[size-1] != 0 && cache1.count(index)) return cache1[index];
    int total1 = nums[index] + robhelper(index+2, nums, size);
    int total2 = robhelper(index+1, nums, size);
    int maxNum =  std::max(total1, total2);

    if(nums[size-1] != 0) cache1[index] = maxNum;
    if(nums[size-1] == 0) cache2[index] = maxNum;
    return maxNum;
}

int rob(vector<int> &nums)
{
    if(nums.empty()) return 0;
    int size = nums.size();
    std::map<int, int> cache;

    vector<int> tmp = nums;
    tmp[size-1] = 0;
    int total1 = nums[0] + robhelper(2, tmp, size);
    int total2 = robhelper(1, nums, size);

    return std::max(total1, total2);
}

TEST_CASE("", "")
{
     std::vector<int> vec1 = {1, 3, 5, 7, 9};
     REQUIRE(14 == rob(vec1));
}
