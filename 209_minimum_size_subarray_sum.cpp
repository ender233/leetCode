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
 * Algorithm refer to : double pointer
 * https://github.com/haoel/leetcode/blob/master/algorithms/cpp/minimumSizeSubarraySum/MinimumSizeSubarraySum.cpp
 */

int minSubArrayLen(int s, vector<int> &nums)
{
    if(nums.empty()) return 0;
    int size = nums.size();

    int beg = 0;
    int end = 0;
    int curtotalNum(0);
    int minNum(9999);
    for(; end<size ;) {
        curtotalNum += nums[end];
        while(curtotalNum >= s) {
            if(beg == end) return 1;
            if(minNum > end-beg+1) minNum = end-beg+1;
            curtotalNum -= nums[beg++];
        }
        ++end;
    }
    return minNum==9999 ? 0 : minNum;
}


TEST_CASE("", "")
{
    std::vector<int> vec1{2,3,1,2,4,3};
    REQUIRE(2 == minSubArrayLen(7, vec1));
    std::vector<int> vec2{};
    REQUIRE(0 == minSubArrayLen(100, vec2));
}
