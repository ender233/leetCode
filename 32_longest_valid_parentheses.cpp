#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>
using namespace std;

/*
 * Algorithm :
 *      ")()())" -> 011110 -> 4 
 *      "()"     -> 11     -> 2
 *      "()(()"  -> 11011  -> 2
 *      as single char is unavailable to know whether it will be removed 
 *      so create an vector to restore the status for every position, then calculate the final result
 */

int longestValidParentheses(string s)
{
    stack<std::pair<char, int>> st;
    vector<int> res(s.size(), 0);
    int curNum(0), maxNum(0);
    int i(0);
    for_each(s.begin(), s.end(), [&](char c){
                do {
                    if(st.empty()) {st.push(std::make_pair(c, i)); break;}
                    char top = st.top().first;
                    int topi = st.top().second;
                    if(top=='('&&c==')') {
                        res[i] = 1;
                        res[topi] = 1;
                        st.pop(); 
                    }
                    else {
                       st.push(std::make_pair(c, i));
                    }
                } while(false);
                ++i;
            });
    //std::copy(res.begin(), res.end(), ostream_iterator<int>(std::cout, " "));
    for_each(res.begin(), res.end(), [&](int j){
                if(j==0) {
                    maxNum = curNum>maxNum? curNum : maxNum;
                    curNum = 0;
                }
                else ++curNum;
            });
    return std::max(curNum, maxNum);
}

TEST_CASE("", "")
{
    REQUIRE(longestValidParentheses(")()())") == 4);
    REQUIRE(longestValidParentheses("()") == 2);
    REQUIRE(longestValidParentheses("()(()") == 2);
}
