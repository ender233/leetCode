#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <algorithm>
#include <prettyprint.hpp>

/* ref:
 * http://en.cppreference.com/w/cpp/algorithm/next_permutation
 */

using namespace std;
vector<int> nextPermuate(vector<int> &nums)
{
    if(nums.empty()) return vector<int>({});

    int size = nums.size();
    int curNum = nums[size-1];
    bool valid(false);

    for(int i=size-2; i>=0; --i) {
        if(nums[i] <curNum) {
            for(int j=size-1; j>i; --j) {
                if(nums[j] > nums[i]) {
                    std::swap(nums[i], nums[j]);
                    std::sort(nums.begin()+i+1, nums.end());
                    valid = true;
                    break;
                }
            }
            break;
        }
        curNum = nums[i];
    }

    if(!valid) return vector<int>({});

    return nums;
}

vector<vector<int>> permute(vector<int> &nums)
{
    if(nums.empty()) return vector<vector<int>>({});
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    res.push_back(nums);
    while(!nextPermuate(nums).empty()) {
        res.push_back(nums);
    }
    return res;
}

TEST_CASE("", "")
{
    /*
    vector<int> vec1 = {1,2,3,5,4};
    std::cout<<"nextPermuate:"<<nextPermuate(vec1)<<std::endl;
    */

    vector<int> vec2 = {1,2,3};//,4,5};
    auto res2 = permute(vec2);
    std::cout<<"res2:"<<res2<<std::endl;
}
