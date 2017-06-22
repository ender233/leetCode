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
 * Divide and Conquer
 * case 1 : 0 maxNum = max(left, right)
 * case 2 : -&  
 *     odd: divede by odd 
 *          maxNum = max(left, right)
 *     even:product all of number
 */

int maxProduct(vector<int> &nums)
{
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    vector<int> posNum;
    // case 1
    int size = nums.size();
    for(int i=0; i< size; ++i)
    {
        if(nums[i] == 0) {
            auto itr = nums.begin();
            vector<int> numsl(itr, itr+i);
            vector<int> numsr(itr+i+1, nums.end());
            int curMax = std::max(maxProduct(numsl), maxProduct(numsr));
            if(curMax < 0) return 0;
            else return curMax;
        }
        if(nums[i] < 0) posNum.push_back(i);
    }

    // case 2
    int resNum(0);
    if(posNum.size() % 2 == 0) {
        std::for_each(nums.begin(), nums.end(), [&](int x){resNum = resNum==0? x : (resNum*x);});
        return resNum;
    }
    else {
        int posSize = posNum.size();
        int maxNum(0);
        for(int i=0; i<posSize; i+=2) {
            int resLeft(0), resRight(0);
            std::for_each(nums.begin(), nums.begin()+posNum[i], [&](int x){resLeft = resLeft==0? x : (resLeft*x);});
            std::for_each(nums.begin()+posNum[i]+1, nums.end(), [&](int x){resRight = resRight==0? x : (resRight*x);});
            int curMax = std::max(resLeft, resRight);
            if(maxNum < curMax) maxNum = curMax;
        }
        return maxNum;
    }
}

TEST_CASE("", "")
{
    vector<int> vec1{2,3,-2,4};
    REQUIRE(6 == maxProduct(vec1));

    vector<int> vec2{2, 3, 5, 0, 6, 7, 0, 11, 11};
    REQUIRE(121 == maxProduct(vec2));

    vector<int> vec3{2, 3, -2, -2, 5};
    REQUIRE(120 == maxProduct(vec3));
    
    vector<int> vec5{2, 2, -2, 2, -2, -1, 1};
    REQUIRE(32 == maxProduct(vec5));

    vector<int> vec6{-2, 0, -1};
    REQUIRE(0 == maxProduct(vec6));

    vector<int> vec7{-3, 0, 1, -2};
    REQUIRE(1 == maxProduct(vec7));
}
