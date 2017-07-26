#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <catch.hpp>
#include <prettyprint.hpp>
using namespace std;

/*
 * 111111   ->   n 1
 *     -> *****   n *
 */
string getNextCount(const string &cur)
{
    //std::cout<<"cur:"<<cur<<std::endl;
    if(cur.size() == 1) return string("11");
    int size = cur.size();   
    int beg = 0;
    int end = beg+1;
    string res("");
    while(end<size) {
        if(cur[beg] != cur[end]) {
            res += (end - beg+'0');
            res += (cur[beg]);
            beg = end;
            end = beg+1;
            continue;
        }
        else {
            ++end; 
        }
    }
    res += (end - beg+'0');
    res += (cur[beg]);
    //cout<<"beg:"<<beg<<" end:"<<end<<" res:"<<res<<endl;

    return res;
}

string countAndSay(int n)
{
    if(1==n) return string("1");
    return getNextCount(countAndSay(n-1));
}

TEST_CASE("", "")
{
    REQUIRE("1" == countAndSay(1));
    REQUIRE("1211" == countAndSay(4));
}
