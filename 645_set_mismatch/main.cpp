#include <iostream>
#include <vector>
#include <set>
#include <prettyprint.hpp>
using namespace std;

/*
 *  集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 *  给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 *
 *  算法：注意缺失元素在首端和尾端的情况.
 */

vector<int> findErrorNums(vector<int> &nums) {
    std::set<int> set1;
    vector<int> res;
    for(auto num : nums) {
       if(set1.find(num) == set1.end()) {
           set1.insert(num);
       }
       else {
           res.push_back(num);
       }
    }

    int firstNum = 1;
    int i = 0;
    for(auto &s : set1) {
        if((s-i) != firstNum) {
            res.push_back(s-1);
            break;
        }
        ++i;
    }

    if(res.size() == 1) res.push_back(*set1.end() + 1);
    return res;
}

int main() {
    vector<int> vec1 = {2,2};
    auto res1 = findErrorNums(vec1);
    std::cout << res1 << std::endl;
    return 0;
}