#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

struct Solution{
    std::map<std::pair<int, int>, int> mapCache;
    int m;
    int n;
    Solution() : m(0), n(0) {
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        if(grid.size() == 0) return 0;
        m = grid.size();
        n = grid[0].size();

       return minPath(0, 0, grid);
    }

    int minPath(int i, int j, vector<vector<int>> &grid)
    {
        if(mapCache.find(make_pair(i, j)) != mapCache.end()) return mapCache[make_pair(i, j)];
        if( i==(m-1) && j==(n-1)) return grid[i][j];
        if(i>= m || j>=n) return INT_MAX;
        int res;
        res = grid[i][j] + std::min(minPath(i+1, j, grid), minPath(i, j+1, grid));

        mapCache[make_pair(i, j)] = res;
        return res;
    }
};


TEST_CASE("", "")
{
    std::vector<vector<int>> vec1{{1,3,1},
                                  {1,5,1},
                                  {4,2,1}};
    Solution s1;
    REQUIRE(s1.minPathSum(vec1) == 7);
}
