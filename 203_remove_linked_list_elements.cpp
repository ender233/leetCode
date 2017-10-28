#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return head;
    ListNode *tmpHead(head);

    ListNode *p1 = NULL;
    ListNode *p2 = head;

    while(p2 != NULL) {
        if(p2->val == val) {
            if(p1 != NULL) {
                ListNode *tmp = p2;
                p2 = p2->next;
                p1->next = p2;
                delete tmp;
            }
            else {
                ListNode *tmp = p2;
                p2 = p2->next;
                tmpHead = p2;
                delete tmp;
            }
            continue;
        }

        p1 = p2;
        if(p2 != NULL) p2 = p2->next;
    }   
    return tmpHead;
}
