#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
#include <sstream>
#include <algorithm>
using namespace std;

/*
 * Algorithm : 
 *  1. run the >> provided by std::stringstream get the number into vector<int>
 *  2. change the size of vectors to the same by resize()
 *  3. compare two vectors to get the bigger one
 *
 * Notes:
 *  1. std::stringstream will not change after running >> so we need calculate the number to be got before run it but not to judge that by while(stringstream x) which is not right
 *
 * Questin:
 * why it comes to error when i use std::count_if to count the number of '.'??
 */

vector<int> getVerVec(string &str)
{
    vector<int> res;
    if(str.empty()) return res;

    std::stringstream stre1(str);
    int initNum(0);
    stre1 >> initNum;
    res.push_back(initNum);
    char c;
    int tmpNum(0);
    //int pCount = std::count_if(str.begin(), str.end(), '.');
    int pCount(0);
    for(auto c : str) {
        if(c=='.') ++pCount;
    }
    for(int i=0; i<pCount; ++i) {
        stre1>>c>>tmpNum;
        res.push_back(tmpNum);
    }
    return res;
}

int compareVersion(string version1, string version2)
{
    vector<int> v1 = getVerVec(version1);
    vector<int> v2 = getVerVec(version2);
    int maxCap = std::max(v1.size(), v2.size());
    v1.resize(maxCap);
    v2.resize(maxCap);

    int size1 = v1.size();
    for(int i=0; i<size1; ++i) {
        v1[i] = v1[i] - v2[i];

        if(v1[i] > 0) return 1;
        else if(v1[i] < 0) return -1;
        else continue;
    }
    return 0;
}

TEST_CASE("", "")
{
    REQUIRE(compareVersion("1", "0") == 1);
    REQUIRE(compareVersion("13.7", "1.7") == 1);
    REQUIRE(compareVersion("1.7", "1.6") == 1);
    REQUIRE(compareVersion("1.6", "1.7") == -1);
    REQUIRE(compareVersion("1.6", "1.6") == 0);
    REQUIRE(compareVersion("1", "1") == 0);
    REQUIRE(compareVersion("01", "1") == 0);
    REQUIRE(compareVersion("1.0.1", "1") == 1);
    REQUIRE(compareVersion("1.0.1", "1.0.1") == 0);
    REQUIRE(compareVersion("1.2.1", "1.0.1") == 1);
    REQUIRE(compareVersion("1.2.1", "1.2.3") == -1);
}
