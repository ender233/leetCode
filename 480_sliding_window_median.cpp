#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <functional>
#include <iterator>
using namespace std;

/*
 * adapter from discussion
 * 思路:
 * 1. 频繁的增删元素, vector就不合适了, 考虑到需要保证元素有序(有重复)选用multiset
 * 2. multiset本身不是随机存储,因此需要保留中间元素的iterator,　在每次增删元素时对其更新
 *
 * 对比#295,　是通过采用两个优先队队列的top来维护中间值的.
 */

//class Solution {
//public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        std::multiset<int> window(nums.begin(), nums.begin()+k);
        // why not for std::advance, nothing return for it.
        //std::multiset<int>::iterator mid = std::advance(window.begin(), k/2);
        auto mid = std::next(window.begin(), k/2 - (1-k%2));

        std::vector<double> resVec;
        int size = nums.size();
        for(int i=k; ; ++i) {
            resVec.push_back(((double)*mid + *next(mid, 1-k%2))/2);
            if(i==size) return resVec;

            window.insert(nums[i]);
            if(nums[i] < *mid) {
                mid--; 
            }
            if(nums[i-k] <= *mid) {
               mid++; 
            }

            window.erase(window.lower_bound(nums[i-k]));
        }
        return resVec;
    }
//};

TEST_CASE("", "")
{
    std::vector<double> res1{1,-1,-1,3, 5, 6};
    std::vector<int> vec1{1,3,-1,-3,5,3,6,7};
    REQUIRE(res1 == medianSlidingWindow(vec1, 3));

    std::vector<double> res2{2.50000};
    std::vector<int> vec2{1,4,2,3};
    REQUIRE(res2 == medianSlidingWindow(vec2, 4));
}
