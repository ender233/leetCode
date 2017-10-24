#define CATCH_CONFIG_MAIN
#include <iostream>
#include <map>
#include <catch.hpp>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Algorithm:　
 *     遍历扫描带上缓存仍然超时
 *     正确的思路应该在每一个位置只找`beautiful num`然后回溯计算，这样非`beautiful num`永远也不会被重复计算
 *     TODO : 使用std::vector<int> 每次不仅传值作为入参　而且有erase删除元素的操作，vector对删除操作不友好，需要优化
 */

int countArrange(int N, vector<int> vec)
{
    if(N<=0) return 1;
    int cnt(0);
    for(int i=0; i<N; ++i) {
        if(vec[i]%N==0 || N%vec[i]==0) {
            vector<int> tmp(vec);
            auto iter = tmp.begin();
            std::advance(iter, i);
            tmp.erase(iter);
            cnt += countArrange(N - 1, tmp);
        }
    }
    return cnt;
}

int countArrangement(int N) {
    std::vector<int>  vec;
    vec.reserve(N);
    for(int i=1; i<=N; ++i) {
        vec.push_back(i);
    }

    return countArrange(N, vec);
}


// 超时
/*
std::map<std::pair<int, int>, bool> mapCache;
bool isBeautifulArray(std::vector<int> &vec) {
    int N = vec.size();
    for(int i=0; i<N; i++) {
        int j = i+1;

        if(mapCache.find(std::make_pair(j, vec[i])) != mapCache.end()) {
            if(mapCache[std::make_pair(j, vec[i])]) continue;
            else return false;
        }
        if(vec[i]%j!=0 && j%vec[i]!=0) {mapCache[std::make_pair(j, vec[i])] = false; return false;}
        else mapCache[std::make_pair(j, vec[i])] = true;
    }
    return true;
}

int countArrangement(int N) {
    std::vector<int> vec;
    vec.reserve(N);
    for(int i=1; i<=N; ++i) {
        vec.push_back(i);
    }

    int num(0);
    do{
        if(isBeautifulArray(vec))  ++num;
    } while(std::next_permutation(vec.begin(), vec.end()));
    return num;
}
 */

TEST_CASE("", "")
{
    REQUIRE(countArrangement(2) == 2);
    REQUIRE(countArrangement(3) == 3);
    REQUIRE(countArrangement(11) == 750);
}

