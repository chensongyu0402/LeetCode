#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    
    struct ListNode *ans, *head;
    
    if(list1 -> val <= list2 -> val) {
        ans = list1;
        list1 = list1 -> next;
    }
    else {
        ans = list2;
        list2 = list2 -> next;
    }
    head = ans;
    while(list1 != NULL && list2 != NULL) {
        if(list1 -> val <= list2 -> val) {
            ans -> next = list1;
            ans = ans -> next;
            list1 = list1 -> next;
        }else {
            ans -> next = list2;
            ans = ans -> next;
            list2 = list2 -> next;
        }
    }
    
    if(list1 != NULL)
        ans -> next = list1;
    
    if(list2 != NULL)
        ans -> next = list2;
    
    return head;
}