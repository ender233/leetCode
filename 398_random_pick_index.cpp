#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <random>
#include <list>
#include <map>
using namespace std;

/*
 * Algorithm: the same as 382
 */
class Solution
{
    public:
        Solution(vector<int> nums) {
            _nums = nums;     
        }
        int pick(int target) {
            std::random_device rd; 
            unsigned int count(0);
            int resIndex;
            int s = _nums.size();
            for(int i=0; i<s; ++i) {
                if(_nums[i] == target && rd()%(++count)==0) resIndex=i;
            }
            return resIndex;
        }
    private:
        vector<int> _nums;
};

TEST_CASE("", "")
{
    std::map<int, int> paramMap;
    vector<int> v1{1, 2, 3, 3, 3};
    Solution *obj = new Solution(v1);
    for(int i=0; i<1000; ++i) {
        int param = obj->pick(3);
        ++paramMap[param];
    }
    for(auto &m : paramMap) {
        std::cout<<m.first<<":"<<m.second<<std::endl;
    }
}
