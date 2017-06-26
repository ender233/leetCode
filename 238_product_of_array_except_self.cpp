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
 *  Description:
 *  Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *  Solve it without division and in O(n).
 *  For example, given [1,2,3,4], return [24,12,8,6]
 *
 *  Algorithm : total = [left] * [right] , 2 times iteration
 */

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res(nums.size(), 1);
    int size = nums.size();
    for(int i=1; i<size; ++i) {
        res[i] = res[i-1] * nums[i-1];
    }

    int right=1;
    for(int i=size-1; i>=0; --i) {
        res[i] *= right;
        right *= nums[i];
    }

    return res;
}

TEST_CASE("", "")
{
    vector<int> vec1{1,2,3,4};
    vector<int> res1 = productExceptSelf(vec1);
}
