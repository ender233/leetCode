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
 * Algorithm : sort
 * Note : 
 *  1. map/unordered_map just can sort by key.
 *  2. sort two elements by std::pair + std::sort
 *
 */

vector<int> topKFrequent(vector<int> &nums, int k)
{
    std::unordered_map<int, int> unorderMap;
    for(auto i : nums) {
        ++unorderMap[i] ;
    }

    vector<pair<int, int>> vec;
    for(auto &p : unorderMap) {
        vec.push_back(p);
    }
    std::sort(vec.begin(), vec.end(), [&](pair<int, int> p1, pair<int, int> p2){
                return p1.second > p2.second; 
            });
    
    vector<int> res;
    int i(0);
    for(auto &p : vec) {
        res.push_back(p.first) ;
        if(++i == k) break;
    }

    return res;
}

TEST_CASE("", "")
{
    vector<int> vec1{1,1,1,2,2,3};
    vector<int> res1{1,2};

    REQUIRE(res1 == topKFrequent(vec1, 2));
}
