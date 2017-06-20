#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <prettyprint.hpp>
using namespace std;

/*
 *  vector<int> -> vector<bit>
 *  check: bytes bit=1 bit=0
 *  Algorithm: bitset
 *  Warnings: bitset[0] is on the rightest which is counter-intuitive
 *  Hint: reverse sequence to record status
 *
 *    Char. number range  |        UTF-8 octet sequence
 *          (hexadecimal)    |              (binary)
 *    --------------------+---------------------------------------------
 *    0000 0000-0000 007F | 0xxxxxxx
 *    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 *    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 *    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 */
bool validUtf8(vector<int> &data)
{
    vector<bitset<8>> bitData;
    for(auto d : data) {
         bitset<8>  bit(d);
         bitData.push_back(bit);
    }
    //std::cout<<"bitData:"<<bitData<<std::endl;
    int size = bitData.size();

    int resetNum(0);
    for(auto itr=bitData.rbegin(); itr!=bitData.rend(); ++itr)
    {
        if((*itr)[7] == 0 && resetNum==0) continue;
        else if((*itr)[7] == 0) return false;

        if((*itr)[7]==1 && (*itr)[6]==0) {
            ++resetNum ;
            continue;
        }

        if(resetNum > 3) return false;
        bitset<8> bit = *itr;
        int i = 0;
        for(; i<=resetNum; ++i) {
            if(bit[7-i] != 1) return false;
        }
        if(bit[7-i] == 0) {
            resetNum = 0;
            continue;
        }
        return false;
    }

    if(resetNum != 0) return false;

    return true;
}

TEST_CASE("", "")
{
    /*
    vector<int> vec1{197, 130, 1};
    REQUIRE(validUtf8(vec1));
    vector<int> vec2{235, 140, 4};
    REQUIRE(!validUtf8(vec2));

    vector<int> vec3{145};
    REQUIRE(!validUtf8(vec3));
    */

    vector<int> vec5{250, 145, 145, 145, 145};
    REQUIRE(!validUtf8(vec5));
}
