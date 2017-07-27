#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool isValid(string s)
{
    if(s.size()%2!=0) return false;
    stack<char> st;
    for_each(s.begin(), s.end(), [&](char c){
            do {
                if(st.empty()) {st.push(c); break;}
                char top = st.top();
                if((c==')'&&top=='(') || (c=='}'&&top=='{') || (top=='['&&c==']')) {
                    st.pop(); 
                }
                else st.push(c);

            } while(0);
        });
    return st.empty();
}

TEST_CASE("", "")
{
    REQUIRE(isValid(string("()[]{}")));
    REQUIRE(!isValid(string("()[{}")));
    REQUIRE(!isValid(string("((")));
}

