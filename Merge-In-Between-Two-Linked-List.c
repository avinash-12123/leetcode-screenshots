/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *prevA = list1;
    for (int i = 0; i < a - 1; i++) {
        prevA = prevA->next;
    }

    struct ListNode *afterB = prevA;
    for (int i = 0; i < b - a + 2; i++) {   
        afterB = afterB->next;
    }

    struct ListNode *tail2 = list2;
    while (tail2->next != NULL) {
        tail2 = tail2->next;
    }

    prevA->next = list2;

    tail2->next = afterB;

    return list1;
}
