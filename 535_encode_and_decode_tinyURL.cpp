#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>
//#include <random>
#include <map>
#include <unordered_map>

using namespace std;

// http://tinyURL/ + **

unordered_map<string, string> enCodeMap;
unordered_map<string, string> deCodeMap;

#include <random>
std::string genRandomKey()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<char> dis1('0', '9');
    std::uniform_int_distribution<char> dis2('a', 'z');
    std::uniform_int_distribution<char> dis3('A', 'Z');

    std::string result;
    for(int i=0; i<6; ++i) {
        size_t r = rd();
        if(r%3 == 0) result += dis1(gen);
        if(r%3 == 1) result += dis2(gen);
        if(r%3 == 2) result += dis3(gen);
    }
    return result;
}

string encode(string longUrl)
{
    std::string key = genRandomKey();
    while(enCodeMap.find(key) != enCodeMap.end()) {
        key = genRandomKey();
    }

    std::string initStr = "http://tinyurl.com/";
    enCodeMap["http://tinyurl.com/" + key] = longUrl;
    deCodeMap[longUrl] = "http://tinyurl.com/" + key;
    return std::string(initStr+key);
}

string decode(string shortUrl)
{
    return enCodeMap[shortUrl];
}

TEST_CASE("end of computation", "result is")
{
    string longUrl("https://leetcode.com/problems/design-tinyurl");
    std::string strResult = encode(longUrl);
    REQUIRE(decode(strResult) == longUrl);
}
