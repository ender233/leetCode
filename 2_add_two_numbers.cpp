#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include "listNode.hpp"
#include <list>

#include <prettyprint.hpp>
using namespace std;

/*
struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

/*
 * Algorithm : iteration
 * Warning : take all the parameter into consideration 
 *     addTwobyBit(NULL, NULL, 1);
 */


ListNode *addTwobyBit(ListNode *l1, ListNode *l2, int c=0)
{
    if(l1==NULL && l2==NULL && c==0) return NULL;
    if(l1==NULL && l2==NULL && c!=0) {
        return new ListNode(c);
    }
    
    int left(0), right(0);
    ListNode *l1Next(NULL), *l2Next(NULL);
    if(l1!=NULL) {left = l1->val; l1Next = l1->next;}
    if(l2!=NULL) {right = l2->val; l2Next = l2->next;}

    ListNode *cur = new ListNode((left+right+c) % 10);
    ListNode *nxt = addTwobyBit(l1Next, l2Next, (left+right+c)/10);
    cur->next = nxt;
    return cur;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return addTwobyBit(l1, l2, 0);
}

TEST_CASE(" ", " ")
{
    list<int> list1{2, 4, 3};
    list<int> list2{5, 6, 4, 5, 8};

    ListNode *l1 = loadListNode(list1);
    ListNode *l2 = loadListNode(list2);
    ListNode *res1 = addTwoNumbers(l1, l2);
    PrintListNode(res1);
}
