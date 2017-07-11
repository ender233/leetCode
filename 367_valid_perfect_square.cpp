#define CATCH_CONFIG_MAIN
#include <catch.hpp>
using namespace std;

double mySqrt(int x) {
    double in = x; 
    double del = 0.0001;
    while(fabs(pow(in, 2) -x) > del) {
        in = (x/in + in)/2;
    }
    return in;
}

bool isPerfectSquare(int num)
{
    double sq = mySqrt(num);
    int sqInt = (int)((sq - (int)sq)*1000000);
    return (sqInt == 0);
}

TEST_CASE("", "")
{
    REQUIRE(isPerfectSquare(16));
    REQUIRE(!isPerfectSquare(14));
    REQUIRE(!isPerfectSquare(681));
}
