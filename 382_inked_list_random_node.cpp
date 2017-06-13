#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <random>
#include <list>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode * loadListNode(std::list<int> &lList)
{
    ListNode *head = NULL;
    if(!lList.empty()) {
        head = new ListNode(lList.front());
        lList.erase(lList.begin());
    }

    ListNode *p = head;
    for(auto &x : lList) {
           p->next = new ListNode(x);
           p = p->next;
    }
    return head;
}

void PrintListNode(ListNode *h)
{
    while(h != NULL) {
        std::cout<<h->val<<",";
        h = h->next;
    }
    std::cout<<std::endl;
}

/*
 * algorithm:
 * https://zh.wikipedia.org/wiki/%E6%B0%B4%E5%A1%98%E6%8A%BD%E6%A8%A3
 * https://en.wikipedia.org/wiki/Reservoir_sampling
 *
 */
class Solution {
public:
    Solution(ListNode *head) 
    {h = head;}

    int getRandom()
    {
        std::random_device  rd;
        int curNum = (h!=NULL) ? h->val : 0;

        ListNode *cur = h;
        int i = 1;
        while(cur->next != NULL) {
            if(rd() % (++i) == 0) curNum = cur->next->val;
            cur = cur->next;
        }
        return curNum;
    }
private:
    ListNode * h;

};

TEST_CASE("", "")
{
    std::list<int> list1{1,2, 3, 4,5};
    ListNode *h1 = loadListNode(list1);
    PrintListNode(h1);

    std::map<int, int> paramMap;
    Solution *obj = new Solution(h1);
    for(int i=0; i<1000; ++i) {
        int param_1 = obj->getRandom();
        ++paramMap[param_1];
    }

    for(auto &m : paramMap) {
        std::cout<<m.first<<":"<<m.second<<std::endl;
    }
}
