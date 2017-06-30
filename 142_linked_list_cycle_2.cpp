#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "listNode.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <prettyprint.hpp>
using namespace std;

/*
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
// Algorightm: double pointer

ListNode *detectCycle(ListNode *head)
{
    if(head == NULL) return NULL;

    ListNode *first = head;
    ListNode *second = head;
    while(second) {
        first = first->next;
        second = second->next;
        if(second == NULL) return NULL;
        second = second->next;
        if(first == second) break;
    }
    if(second== NULL) return NULL;
    std::cout<<"current P:"<<second->val<<std::endl;

    first = head;
    //second = second->next;
    while(first != second) { 
        first = first->next;
        second = second->next;
    }
    return first;
}


TEST_CASE("", "")
{
    list<int> list1{1,2,3,4};
    ListNode *head1 = loadListNode(list1);
    REQUIRE(!detectCycle(head1));

    ListNode *p1 = head1->next;
    ListNode *p2 = head1->next->next->next;
    p2->next = p1;
    REQUIRE(detectCycle(head1));

    ListNode *pNULL = NULL;
    REQUIRE(!detectCycle(pNULL));
}
