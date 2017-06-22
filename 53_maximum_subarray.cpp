#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    if(nums.empty()) return 0;

    int size = nums.size();
    int maxNum = nums[0];
    int sumNum = nums[0];
    for(int i=1; i<size; ++i)
    {
        if(sumNum < 0) sumNum = 0;

        sumNum += nums[i];
        if(maxNum < sumNum) maxNum = sumNum;
    }

    return maxNum;
}

TEST_CASE("", "")
{
    vector<int> vec1{-2,1,-3,4,-1,2,1,-5,4};
    vector<int> res1{4,-1,2,1};
    REQUIRE(6 == maxSubArray(vec1));

}
