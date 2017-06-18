#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <prettyprint.hpp>
using namespace std;

/*
 * Algorithm: DFS
 * Warnings: do not increment/decrement for i/j in loop
 *
 */

void resetRelatedIsland(vector<vector<char>> &grid, int i, int j, int iMax, int jMax)
{
    if(i<0 || j<0 || i>=iMax || j>=jMax) return;
    if(grid[i][j] == '0') return;

    grid[i][j] = '0';
    resetRelatedIsland(grid, i-1, j, iMax, jMax);
    resetRelatedIsland(grid, i, j-1, iMax, jMax);
    resetRelatedIsland(grid, i+1, j, iMax, jMax);
    resetRelatedIsland(grid, i, j+1, iMax, jMax);
}

int numIslands(vector<vector<char>> &grid)
{
    if(grid.empty()) return 0;
    int resNum(0);
    int iMax = grid.size();
    int jMax = grid[0].size();
    for(int i=0; i<iMax; ++i)
        for(int j=0; j<jMax; ++j)
        {
            if(grid[i][j] == '1') 
            {
                ++resNum;
                grid[i][j] = '0';
                resetRelatedIsland(grid, i-1, j, iMax, jMax);
                resetRelatedIsland(grid, i, j-1, iMax, jMax);
                resetRelatedIsland(grid, i+1, j, iMax, jMax);
                resetRelatedIsland(grid, i, j+1, iMax, jMax);

                //std::cout<<"i:"<<i<<" j:"<<j<<std::endl;
                //std::cout<<"current islands:"<<grid<<std::endl;
            }
        }
    return resNum;
}

TEST_CASE("", "")
{
    vector<vector<char>> input1{{'1','1','1','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    REQUIRE(numIslands(input1) == 3);

    vector<vector<char>> input2{{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    REQUIRE(numIslands(input2) == 1);
}

