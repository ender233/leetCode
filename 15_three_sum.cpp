#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "catch.hpp"
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res0;
    int length = nums.size();
    std::sort(nums.begin(), nums.end()); 
    for(int i=0; i<length-2; ++i) {
        int num1 = nums[i];
        int index2 = i+1;
        int index3 = length-1;
        while((num1 + nums[index2] + nums[index3]) != 0 && (index2 < index3)) {
            int totalNum =  num1 + nums[index2] + nums[index3];
            if(totalNum < 0) {
                ++index2;
                continue;
            }
            else if(totalNum > 0) {
                ++index3;
                continue
            }
            else {
                 vector<int>  res;
                 res.push_back(nums[i]);
                 res.push_back(nums[index2]);
                 res.push_back(nums[index3]);
                 res0.push_back(res);
            }
        }
    }
    return res0;
}

TEST_CASE("", "")
{
     vector<int> nums1{-1, 0, 1, 2, -1, -4}
     vector<vector<int>> nums{{-1,0,1}, {-1,-1,2}};
     REQUIRE(nums == threeNum(nums1));
}
