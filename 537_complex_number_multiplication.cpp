#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>

#include <stdio.h>
#include <sstream>

using namespace std;
string complexNumberMultiply(string a, string b)
{
    std::stringstream s1(a), s2(b);
    std::stringstream res;
    
    int x, y;
    int x1, y1;
    char f;
    s1 >> x >> f >> y >> f;
    s2 >> x1 >> f >> y1 >> f;
    
    int X = x*x1 - y*y1;
    int Y = y*x1 + x*y1;

    // solution 1: cout style
    res<<X<<"+"<<Y<<"i";
    return res.str();

    // solution 2: printf style
    //const char *fmt = "%d+%di";
    //int sz = snprintf(NULL, 0, fmt, X, Y);
    //char buf[sz + 1];
    //snprintf(buf, sizeof(buf), fmt, X, Y);
    //string res2(buf);
    //return res2;
}

TEST_CASE("", "")
{
    REQUIRE(complexNumberMultiply("1+-1i", "1+-1i") == std::string("0+-2i"));
    REQUIRE(complexNumberMultiply("1+1i", "1+1i") == std::string("0+2i"));
}
