#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <random>
#include <list>
#include <map>
using namespace std;

/*
 * Algorightm: Greedy
 * Warning: Vector<int>, when use the first index, make sure that it will be available all the time
 */

typedef pair<int, int> PairInt;
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
{
    vector<pair<int, int>> resVec;
    std::sort(people.begin(), people.end(), [&](PairInt &lhs, PairInt &rhs){
                if(lhs.first > rhs.first) return true;
                else if(lhs.first == rhs.first) return lhs.second < rhs.second;
                else return false;
            });

    if(!people.empty()) resVec.push_back(people[0]);
    auto it = resVec.begin();
    for(int i=1; i<people.size(); ++i)
    {
        int index = people[i].second; 
        // Warning
        it = resVec.begin();
        resVec.insert(it+index, people[i]);
    }
    return resVec;
}

TEST_CASE("", "")
{
    vector<PairInt> inVec1 = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<PairInt> res1 = reconstructQueue(inVec1);
    for(auto &p : res1) {
        std::cout<<p.first<<" "<<p.second<<std::endl;
    }
}
