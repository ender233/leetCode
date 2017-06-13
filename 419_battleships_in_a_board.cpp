#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
using namespace std;

std::vector<vector<char> > getVecChar(std::vector<string> &instr)
{
    vector<vector<char> > outVec;
    for(auto str : instr) {
        vector<char> vChar;
        for_each(str.begin(), str.end(), [&](char c){vChar.push_back(c);});
        outVec.push_back(vChar);
    }
    return outVec;
}

int countBattleships(vector<vector<char>> &board)
{
    int totalNum(0);
    int m = board.size();
    int n = board[0].size();
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
        {
            if((board[i][j]=='X') && ((i==0 && j==0) || (i==0 && board[i][j-1]!='X') || (j==0 && board[i-1][j]!='X') || ((i!=0 && j!=0) && (board[i-1][j]!='X') && (board[i][j-1]!='X')))) 
            {
                cout<<"i:"<<i<<" j:"<<j<<std::endl;
                ++totalNum;
            }
        }
    return totalNum;

}

TEST_CASE("", "")
{
    vector<vector<char> > board1 = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    REQUIRE(2 == countBattleships(board1));

    vector<string> vboard2 = {".XXXX.X.X.","X.......X.",".X.X.X..X.","X.X.X...X.",".X.X..X..X"};
    vector<vector<char> > board2 = getVecChar(vboard2);
    REQUIRE(14 == countBattleships(board2));
}
