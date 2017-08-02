#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    int size = nums.size();
    for(int i=0; i<size; ++i)
    {
        for(int j=i+1; j<size; ++j) {
            if(target == nums[i]+nums[j]) {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

TEST_CASE("", "")
{
    vector<int> vec1{0, 1};
    vector<int> nums{2,7,11,15};
    REQUIRE(vec1 == twoSum(nums, 9));

    vector<int> vec2{0,2};
    vector<int> nums2{-3,4,3,90};
    REQUIRE(vec2 == twoSum(nums2, 0));
}
