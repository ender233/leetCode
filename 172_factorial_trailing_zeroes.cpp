#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;


int trailingZeroes(int n)
{
    int totalNum(0);
    while(n){
        n /= 5;
        totalNum += n;
    }
    return totalNum;
}
