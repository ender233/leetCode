#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <algorithm>
#include <string>
#include <prettyprint.hpp>

using namespace std;

string getPermutation(int n, int k)
{
    if(n==0) return std::string("");
    vector<char> vec1;
    for(int i=1; i<=n; ++i) {
        vec1.push_back('0'+i);
    }
    --k;
    while(std::next_permutation(vec1.begin(), vec1.end())) {
        if(--k == 0)  break;
    }

    return std::string(vec1.begin(), vec1.end());
}

TEST_CASE("", "")
{
    REQUIRE(string("213") == getPermutation(3, 3));
}
