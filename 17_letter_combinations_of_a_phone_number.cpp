#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

/*
 * char -> string   string str({c});
 */

class Solution
{
private:
    map<char, vector<char>> initMap;

public:
    Solution(){initMaping(initMap);}
    void initMaping(map<char, vector<char>> &initMap)
    {
        initMap['2'] = {'a', 'b', 'c'};
        initMap['3'] = {'d', 'e', 'f'};
        initMap['4'] = {'g', 'h', 'i'};
        initMap['5'] = {'j', 'k', 'l'};
        initMap['6'] = {'m', 'n', 'o'};
        initMap['7'] = {'p', 'q', 'r', 's'};
        initMap['8'] = {'t', 'u', 'v'};
        initMap['9'] = {'w', 'x', 'y', 'z'};
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits.empty()) return res;

        int size = digits.size();
        if(size == 1) {
            vector<char> vecMap = initMap[digits[0]];
            for(auto cha : vecMap) res.push_back(string({cha}));
            return res;
        }

        char c = digits[0];
        vector<char> chVc = initMap[c];
        vector<string> retmp = letterCombinations(digits.substr(1));
        for(auto cha : chVc) {
            for(auto str : retmp) {
                res.push_back(cha + str);
            }
        }

        return res;
    }
};



TEST_CASE("", "")
{
    Solution s1;
    vector<string> v1 = s1.letterCombinations(string("23"));
    std::cout<<"v1:"<<v1<<std::endl;
}
