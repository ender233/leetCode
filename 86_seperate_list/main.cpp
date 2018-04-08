//
// Created by liu on 18-4-8.
//
#include <iostream>
#include "../listNode.hpp"
#include <list>
using namespace std;

/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
例如，
给定1->4->3->2->5->2 和 x = 3,
返回1->2->2->4->3->5.
 */

/*  算法：
 *  遍历找到(val >= x)的节点(第一个指针)，遍历之后的所有元素找到（val < x）应该放到第一个指针之前.
 *  最终分成两个部分，左侧都是(<x)右侧都是(>=x)，且相对位置和初始位置一样.
 *  注意点： 因为是单向链表，因此需要存储前趋并在位置移动后刷新
 */

bool lessThanX(int value, int x) {
    return value < x;
}

bool largerThanX(int value, int x) {
    return value > x || value == x;
}

ListNode* partition(ListNode * head, int x)
{
    if(head == NULL) return NULL;

    ListNode *root = head;
    ListNode *p1 = head;
    ListNode *p2;// = head->next;

    ListNode *p1re =  NULL;
    ListNode *p2re = p1;
    while(p1 != NULL && p1->next != NULL) {
        p2 = p1->next;
        p2re = p1;
        //std::cout << "p1:" << p1->val << std::endl;
        if(largerThanX(p1->val, x)) {
            while(p2 != NULL) {
                if(lessThanX(p2->val, x)) {
                    // for p2
                    p2re->next = p2->next;
                    p2->next = p1;

                    if(p1re != NULL){
                        p1re->next = p2;
                    }
                    else {
                        root = p2;
                    }
                    p1re = p2;
                    p2 = p2re;
                }
                p2re = p2;
                p2 = p2->next;
            }
        }
        p1re = p1;
        p1 = p1->next;
    }

    return root;
}

int main()
{
    list<int> list1 = {1,4,3,2,5,2};
    ListNode *head = loadListNode(list1);
    PrintListNode(head);

    ListNode *res = partition(head, 3);
    PrintListNode(res);

    list<int> list2 = {1,3,2};
    ListNode *head2 = loadListNode(list2);
    PrintListNode(head2);
    ListNode *res2 = partition(head2, 3);
    PrintListNode(res2);

    list<int> list3 = {3,1,2};
    ListNode *head3 = loadListNode(list3);
    PrintListNode(head3);
    ListNode *res3 = partition(head3, 3);
    PrintListNode(res3);
}
