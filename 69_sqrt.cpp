#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "timeBench.hpp"

using namespace std;

/*
 * best solution1:
 * newton's method
 * line formula : y - y0 = k(x - x0);
 *
 * solution2: iteration
 */

double mySqrt2(int x) {
    double in = x; 
    double del = 0.0001;
    while(fabs(pow(in, 2) -x) > del) {
        in = (x/in + in)/2;
    }
    return in;
}

double mySqrt(int x)
{
    if(x==0 || x==1) return x;
    double delta = 0.0001;
    double initNum = x/2;
    double curRes = initNum*initNum;
    double begin = 0;
    double end = x;
    while(fabs(curRes - x) > delta) {
        if(curRes > x) {
            end = initNum;
        }
        else {
            begin = initNum;
        }
        initNum = begin + (end-begin)/2;
        //std::cout<<"initNum:"<<initNum<<" begin:"<<begin<<" end:"<<end<<std::endl;
        curRes = initNum * initNum;
    }   
    return initNum;
}

TEST_CASE("", "")
{
    /*
    REQUIRE(5 == mySqrt(25));
    REQUIRE(1 == mySqrt(1));
    REQUIRE(0 == mySqrt(0));
    */
    //REQUIRE(fabs(1.4142 - mySqrt(2)) < 0.0001);
    //REQUIRE(6 == mySqrt(36));
    //REQUIRE(6 == mySqrt2(36));

    TimeRecord t;
    t.printTimeDiff("begin");
    for(int i=0; i<100000; ++i) {
        double tmp = mySqrt2(i);
    }
    t.printTimeDiff("mySqrt2");

    for(int i=0; i<100000; ++i) {
        double tmp = mySqrt(i);
    }
    t.printTimeDiff("mySqrt");
}
