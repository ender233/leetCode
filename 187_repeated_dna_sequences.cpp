#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

/*
 * Algorithm : 
 * 1. b_tree? TODO
 * https://www.shiyanlou.com/courses/693/labs/2286/document
 *
 * 2. unordered_map
 * A C G T -> 00 01 10 11
 *
 * encode by asc2:
 *  A -> 65+1 % 5 = 1
 *  C -> 67+1 % 5 = 3
 *  G -> 71+1 % 5 = 2
 *  T -> 84+1 % 5 = 0
 */

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> resStr;
    std::unordered_map<int, int> hash_se;
    int size = s.size();
    int curNum(0);
    for(int i=0; i<size; ++i) {
        curNum = (curNum<<2) | (s[i]+1)%5;
        curNum = curNum & 0x0fffff;
        if(i<9) continue;

        if(hash_se[curNum]++ == 1) {
            resStr.push_back(s.substr(i-9, 10));
        }
    }

    return resStr;
}

TEST_CASE("", "")
{
    std::string str1("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> res1{"AAAAACCCCC", "CCCCCAAAAA"};
}
