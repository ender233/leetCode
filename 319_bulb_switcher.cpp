#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

int bulbSwitch(int n)
{
    return (int)sqrt(n);
}

TEST_CASE("", "")
{
    REQUIRE(1 == bulbSwitch(3));
}

