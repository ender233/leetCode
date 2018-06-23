#include <iostream>
#include <string>
#include <vector>
#include <prettyprint.hpp>
using namespace std;
/*
 * 算法: 贪心算法
 * 前两个元素如果确定，按照这个序列推断是否满足fibonacci序列，不满足返回并回退状态
 * 前两个元素的确认需要二层循环即可
 */

bool findNextTarget(const string &s, int j, int num1, int num2, vector<int> &res) {
    if(j == s.size()) return true;
    int targetNum = num1 + num2;
    std::string targetStr = std::to_string(targetNum);

    std::string::size_type sub =  s.find(targetStr, j);
    //std::cout << "sub:" << sub << " targetStr:" << targetStr << std::endl;
    if(sub == std::string::npos || sub != j) 
        return false;
    else {
        res.push_back(targetNum);
        return findNextTarget(s, sub+targetStr.size(), num2, targetNum, res);
    }
}

vector<int> splitIntoFibonacci(string s) {
    int size = s.size();
    vector<int> res;
    bool flag = false;
    for(int i=0; i<size-2; ++i) {
        if(i+1 > 10) return res;
        if(i>0 && s[0]=='0') return res;

        for(int j=i+1; j<size-1; ++j) {
            if(j-i > 10) break;
            if(j>(i+1) && s[i+1]=='0') break;

            char *end;
            int num1 = std::strtol(s.substr(0, i+1).c_str(), &end, 10);
            int num2 = std::strtol(s.substr(i+1, j-i).c_str(), &end, 10);
            res.push_back(num1);
            res.push_back(num2);

            int target =  num1 + num2;
            //std::cout << "num1:" << num1 << " num2:" << num2 << std::endl;
            if(findNextTarget(s, j+1, num1, num2, res)) {
                flag = true;
                break;
            }
            else {
                res.clear();
            }
        }
        if(flag) break;
    }

    return res;
}

void printVec(const vector<int> &v) {
    for(auto s : v) {
        std::cout << s << std::endl;
    }
}

int main()
{
    string s1("1234562579");
    std::vector<int> v1 = splitIntoFibonacci(s1);
    printVec(v1);
    std::cout<<"\n";

    std::cout<<"s2:""\n";
    string s2("11235813");
    auto v2 = splitIntoFibonacci(s2);
    printVec(v2);
    std::cout<<"\n";

    std::cout<<"s3:""\n";
    string s3("0000");
    auto v3 = splitIntoFibonacci(s3);
    printVec(v3);
    std::cout<<"\n";

    std::cout<<"s4:""\n";
    string s4("0123");
    auto v4 = splitIntoFibonacci(s4);
    printVec(v4);
    std::cout<<"\n";
}
