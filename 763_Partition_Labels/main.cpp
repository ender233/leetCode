#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <prettyprint.hpp>
using namespace std;

vector<int> partitionLabels(string S)
{
    std::map<char, int> lastLables;
    int size = S.size();
    for(int i=0; i<size; ++i) {
        lastLables[S[i]] = i;
    }

    vector<int> res;
    if(S.empty()) return res;
    int endIndex = 0;
    int beginIndex = 0;
    for(int j=0; j<size; ++j) {
        char curChar = S[j];
        int lastIndex = lastLables[curChar];

        if (lastIndex > endIndex) {
            endIndex = lastIndex;
            continue;
        }
        if(j == endIndex) {
            res.push_back(endIndex - beginIndex +1);
            beginIndex = endIndex+1;
            endIndex = beginIndex;
            continue;
        }
    }
    return res;
}

int main() {
    std::string s1("ababcbacadefegdehijhklij");
    std::vector<int> res1 = partitionLabels(s1);
    std::cout<<"res1:"<<res1<<std::endl;

    std::string s2("vhaagbqkaq");
    std::vector<int> res2 = partitionLabels(s2);
    std::cout<<"res2:"<<res2<<std::endl;

    std::string s3("ababcbacadefegdehijhklij");
    std::vector<int> res3 = partitionLabels(s3);
    std::cout<<"res3:"<<res3<<std::endl;

    return 0;
}