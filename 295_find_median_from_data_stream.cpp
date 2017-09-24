#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

/*
 * Adapter from 
 * https://zhuanlan.zhihu.com/p/29595813?group_id=894858075599671296
 */

class MedianFinder {
private:
    // 1. vector: 每次findMedian时std::sort TLE
    // 2. list/set: 不支持随机存取
    // std::vector<int> nums_;
    // std::list<int> nums_;
    priority_queue<int> nums1_;
    // lambda-expression is not allowed in template arguments
    //priority_queue<int, std::vector<int>, [](const int &x, const int &y){return x>y;}> nums2_;
    priority_queue<int, std::vector<int>, std::greater<int>> nums2_;

public:

    void print() {
        priority_queue<int> tmp1 = nums1_;
        priority_queue<int, std::vector<int>, std::greater<int>> tmp2 = nums2_;
        std::cout<<"nums1:"<<std::endl;
        while(!tmp1.empty()) {
            std::cout<<tmp1.top()<<" ";
            tmp1.pop();
        }
        std::cout<<"\n";
        
        std::cout<<"nums2:"<<std::endl;
        while(!tmp2.empty()) {
            std::cout<<tmp2.top()<<" ";
            tmp2.pop();
        }
        std::cout<<"\n";
        std::cout<<"\n";
    }
    MedianFinder() {
     
    }

    void addNum(int num) {
        if(nums1_.empty()) {nums1_.push(num); return;}
        if(nums2_.empty()) {
            nums1_.push(num);
            int topNum = nums1_.top();
            nums1_.pop();
            nums2_.push(topNum);
            return;
        }

        int max = nums1_.top();
        int min = nums2_.top();

        if(num >= min) {
            nums2_.push(num);
            if(nums2_.size() > nums1_.size()) {
                int min = nums2_.top();
                nums2_.pop();
                nums1_.push(min);
            }
        }
        else //( num <= max) {
        {
            nums1_.push(num);
            if(nums1_.size() - nums2_.size() > 1) {
                int max = nums1_.top();
                nums1_.pop(); 
                nums2_.push(max);
            }
        }
    }

    double findMedian() {
        //std::cout<<"top1:"<<nums1_.top()<<" top2:"<<nums2_.top()<<std::endl;
        if(nums1_.size() == nums2_.size()) {
            return (double)(nums1_.top()+nums2_.top())/2;
        }
        else return nums1_.top();
    }
};

// example
/*
MedianFinder obj = new MedianFinder();
obj.addNum(num);
double param_2 = obj.findMedian();
*/

TEST_CASE("", "") {
    MedianFinder* obj1 = new MedianFinder();
    obj1->addNum(2);
    obj1->addNum(1);
    obj1->addNum(3);
    REQUIRE(fabs(obj1->findMedian()-2) < 0.000001);
    obj1->addNum(4);
    //obj1->print();
    REQUIRE(fabs(obj1->findMedian()-2.5) < 0.000001);
}
TEST_CASE("", "") {
   MedianFinder* obj1 = new MedianFinder();
    obj1->addNum(-1);
    obj1->addNum(-2);
    obj1->addNum(-3);
    obj1->addNum(-4);
    //obj1->print();
    REQUIRE(fabs(fabs(obj1->findMedian())-2.5) < 0.000001);
}
TEST_CASE("", "") {
    // 40 12 16 14 35 19 34
    MedianFinder *obj = new MedianFinder();
    obj->addNum(40);
    obj->addNum(12);
    obj->addNum(16);
    obj->addNum(14);
    obj->addNum(35);
    //obj->print();
    obj->addNum(19);
    //obj->print();
    REQUIRE(fabs(fabs(obj->findMedian())-17.5) < 0.000001);
    obj->addNum(34);
    //obj->print();
    REQUIRE(fabs(fabs(obj->findMedian())-19) < 0.000001);
}
