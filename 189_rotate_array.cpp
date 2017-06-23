#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

void rotate(vector<int> & nums, int k)
{
    int size = nums.size();
    if(k == size) return;
    if(k > size) k = k%size;

    vector<int> tmp(nums.begin()+size-k, nums.end());
    for(int i=size-k-1; i>=0; --i) {
        nums[i+k] = nums[i];
    }

    int x(0);
    for(auto j : tmp) {
        nums[x++] = j;
    }
}

TEST_CASE("", "")
{
    vector<int> vec1{1,2,3,4,5,6,7};
    vector<int> res1{5,6,7,1,2,3,4};
    rotate(vec1, 3);
    REQUIRE(vec1 == res1);

    vector<int> vec2{1,2,3,4,5,6};
    vector<int> res2{2,3,4,5,6,1};
    rotate(vec2, 11);
    REQUIRE(vec2 == res2);
}
