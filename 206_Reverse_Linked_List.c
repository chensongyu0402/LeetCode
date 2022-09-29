/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    if(!head || !head -> next)
        return head;
    struct ListNode *cur = head, *next = NULL, *pre = NULL;
    while(cur) {
        next = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}