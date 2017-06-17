#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <map>
#include <prettyprint.hpp>

/*
 * Algorithm :  hash
 *
 */

using namespace std;
void initAlp(map<char, int> &alpmap)
{
    alpmap['Q'] = 1;
    alpmap['W'] = 1;
    alpmap['E'] = 1;
    alpmap['R'] = 1;
    alpmap['R'] = 1;
    alpmap['T'] = 1;
    alpmap['Y'] = 1;
    alpmap['U'] = 1;
    alpmap['I'] = 1;
    alpmap['O'] = 1;
    alpmap['P'] = 1;

    alpmap['A'] = 2;
    alpmap['S'] = 2;
    alpmap['D'] = 2;
    alpmap['F'] = 2;
    alpmap['G'] = 2;
    alpmap['H'] = 2;
    alpmap['J'] = 2;
    alpmap['K'] = 2;
    alpmap['L'] = 2;

    alpmap['Z'] = 3;
    alpmap['X'] = 3;
    alpmap['C'] = 3;
    alpmap['V'] = 3;
    alpmap['B'] = 3;
    alpmap['N'] = 3;
    alpmap['M'] = 3;
}

char change2Upp(char s) {
    if(s<='z' && s >='a')
        return s - ('a' - 'A');
    return s;
}

vector<string> findWords(vector<string> & words)
{
    map<char, int> m;
    initAlp(m);

    vector<string> resStr;
    for(auto &w : words) {
        int li = m[change2Upp(w[0])];
        bool f(true);
        for(auto &s : w)  {
            char s1 = change2Upp(s);
            if(m[s1] != li) {
                f = false;
                break;
            }
        }

        if(f) resStr.push_back(w);
    }

    return resStr;
}

TEST_CASE("", "")
{
    vector<string> input1{"Hello", "Alaska", "Dad", "Peace"};
    vector<string> ouput1{"Alaska", "Dad"};

    REQUIRE(findWords(input1) == ouput1);

    vector<string> input2{"adsdf", "sfd"};
    vector<string> ouput2{"adsdf", "sfd"};
    REQUIRE(findWords(input2) == ouput2);
}
