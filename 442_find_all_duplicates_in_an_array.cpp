#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "listNode.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

/*
 * 1. 遍历两遍实际上的时间复杂度也是O(n)
 * 2. 单次遍历的时候，只有当前节点位置都元素都放置到对应位置才可以继续前进
 * 3. 两次遍历的思路是不同的
 *
 */

vector<int> findDuplicates(vector<int> &nums)
{
    std::vector<int> res;
    int size = nums.size();

    for(int i=0; i<size; ) {
        if(nums[i] != nums[nums[i]-1]) {
        //if(nums[i] != i+1) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
        else ++i;
    }

    for(int j=0; j<size; ++j) {
        if(nums[j] != j+1) {
            res.push_back(nums[j]);
        }
    }
    return res;
}

TEST_CASE("", "")
{
    std::vector<int> res1{3,2};
    std::vector<int> vec1{4,3,2,7,8,2,3,1};
    REQUIRE(res1 == findDuplicates(vec1));
}
