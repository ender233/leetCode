#define CATCH_CONFIG_MAIN
#include <iostream>
#include <map>
#include <catch.hpp>
using namespace std;

/*
 *  Algorithm:
 *      Adapter from https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
 *      root Node 1->n
 *      left:  numTrees(1)->numTrees(n-1)
 *      right: numTrees(n-1)->numTrees(1)
 */

class Solution
{
public:
    std::map<int, int> mpCache;
public:
    Solution() {
        mpCache[0] = 1;
        mpCache[1] = 1;
        mpCache[2] = 2;
    }

    int numTrees(int n)
    {
        if(mpCache.find(n) != mpCache.end()) return mpCache[n];
        for(int i=1; i<=n; i++) {
            mpCache[n] += numTrees(i-1) * numTrees(n-i);
        }
        return mpCache[n];
    }
};

TEST_CASE("", "")
{
    Solution s;
    REQUIRE(s.numTrees(3) == 5);
}

