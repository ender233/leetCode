#include <iostream>
#include <vector>
#include <initializer_list>
#include <cassert>
#include <prettyprint.hpp>
using namespace std;

// [4,3,2,7,8,2,3,1]
// -> [5, 6]
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int size = nums.size();
    for(int i=0; i<size; ) {
        if(nums[i] != nums[nums[i]-1]) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
        else ++i;
    }

    //std::cout<<nums<<std::endl;
    std::vector<int> res;
    for(int j=0; j<size; ++j) {
        if(nums[j] != j+1) {
            res.push_back(j+1);
        }
    }
    return res;
}

int main() {
    std::vector<int> vec1{4,3,2,7,8,2,3,1};
    std::vector<int> res1{5,6};
    std::vector<int> res = findDisappearedNumbers(vec1);
    std::cout<<res<<std::endl;
    return 0;
}