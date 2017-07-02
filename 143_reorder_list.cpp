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

/*
 * Algorithm : record the pointer in std::vector
 * Notes: clear the tail pointer
 */

vector<ListNode *> getListVec(ListNode *head)
{
   vector<ListNode *> res;

   while(head != NULL) {
       res.push_back(head);
       head = head->next;
   }
   return res;
}

void reorderList(ListNode *head)
{
    vector<ListNode *> resVec = getListVec(head);
    int size = resVec.size();
    ListNode *cur = head;
    ListNode *nxt = NULL;
    for(int i=0; i<size ; ++i) {
       if(i % 2 == 0) {
           nxt = resVec[i/2];
       }
       else {
           nxt = resVec[(size-1)-(i-1)/2];
       }
       cur->next = nxt; 
       cur = nxt;
       if(i==size-1) cur->next=NULL;
    }
    // Warning compling on leetCode repalce it with 
    // if(i==size-1) cur->next=NULL
    // cur->next = NULL;
}

TEST_CASE("", "")
{
    list<int> vec1{1,2,3,4};
    ListNode *list1 =  loadListNode(vec1);

    reorderList(list1);
    PrintListNode(list1);

    list<int> vec2{1};
    ListNode *list2 =  loadListNode(vec2);

    reorderList(list2);
    PrintListNode(list2);
}
