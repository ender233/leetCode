#pragma once
#include <list>

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
