#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
using namespace std;

int hammingDistance(int x, int y)
{
    int resnum(0);
    int res = x ^ y;
    while(res!=0) {
        if(res & 0x01) {
            ++resnum;
        }
        res = res>>1;
    }
    return resnum;
}

TEST_CASE("", "")
{
    REQUIRE(2==hammingDistance(1, 4));
}
