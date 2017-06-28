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
 * Algorithm: calculation of period of circulating decimal 
 *      vector1: store remainder for every round
 *      vector2: store the result for every round
 * tricks: how to judge whether two elements have the same property () ^ () ?
 *
 */

string fractionToDecimal(int numerator, int denominator)
{
    if(numerator == 0) return "0";
    string res = ((numerator>0) ^ (denominator>0)) ? "-" : "";
    long numerator1 = abs((long)numerator);
    long denominator1 = abs((long)denominator);
    
    long intPart = numerator1 / denominator1;
    vector<char> fracStr;
    vector<int> reVec;
    long remain = numerator1 % denominator1;

    while(std::find(reVec.begin(), reVec.end(), remain) == reVec.end() && remain!=0) {
        reVec.push_back(remain);
        int curFra = remain*10 / denominator1;
        remain = remain*10 % denominator1;

        fracStr.push_back(curFra+'0');
    }

    std::stringstream ss; 
    string tmp("");
    if(remain == 0) {
        ss<<intPart;
        ss>>tmp;
        res += tmp;
        if(!fracStr.empty()) {
            res += '.';
            for_each(fracStr.begin(), fracStr.end(), [&](char c){res+=c;});
        }
    }
    else {
        int rep(0);
        for(int i=0; i<reVec.size(); ++i) {
            if(reVec[i] == remain) {
                rep = i; continue;
            }
        }
        ss<<intPart;
        ss>>tmp;
        res += tmp;
        res += '.';

        for(int j=0; j<rep; ++j) {
            res += fracStr[j];
        }
        res += '(';
        for(int i=rep; i<fracStr.size(); ++i) {
            res += fracStr[i];
        }
        res += ')';
    }
    return res;
}

TEST_CASE(" ", "")
{
    REQUIRE(string("0.5") == fractionToDecimal(1, 2));
    REQUIRE(string("2") == fractionToDecimal(2, 1));
    REQUIRE(string("0.(6)") == fractionToDecimal(2, 3));
    REQUIRE(string("2147483648") == fractionToDecimal(-2147483648, -1));
    REQUIRE(string("-6.25") == fractionToDecimal(-50, 8));
}
