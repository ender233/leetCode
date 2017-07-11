#define CATCH_CONFIG_MAIN
#include <catch.hpp>

using namespace std;

bool judgeSquareSum(int c)
{
    if(c == 0) return true;
    int res = (int)sqrt(c);
    double tmp;
    for(int i=1; i<res+1; ++i) {
        tmp = sqrt(c-pow(i, 2));
        int tmpInt = (int)((tmp - (int)tmp)*1000000);
        if(tmpInt == 0) return true;
    }
    return false;
}

TEST_CASE("", "")
{
    REQUIRE(true == judgeSquareSum(5));
    REQUIRE(false == judgeSquareSum(3));
    REQUIRE(true == judgeSquareSum(2));
}
