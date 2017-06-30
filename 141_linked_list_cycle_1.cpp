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
bool hasCycle(ListNode *head)
{
    if(head == NULL) return NULL;
    ListNode *p = head;
    ListNode *q = head->next;
    while(q) {
        if(q==p) return true;
        p = p->next; 
        q = q->next;
        if(q == NULL) return false;
        q = q->next;
    }
    return false;
}

TEST_CASE("", "")
{
    list<int> list1{1,2,3,4};
    ListNode *head1 = loadListNode(list1);
    REQUIRE(!hasCycle(head1));

    ListNode *p1 = head1->next;
    ListNode *p2 = head1->next->next->next;
    p2->next = p1;
    REQUIRE(hasCycle(head1));

    ListNode *pNULL = NULL;
    REQUIRE(!hasCycle(pNULL));
}
