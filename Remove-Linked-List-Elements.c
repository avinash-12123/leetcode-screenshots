/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return head;

    while (head != NULL && head->val == val)
        head = head->next;
    if (head == NULL)
        return NULL;

    struct ListNode* trav = head;
    while (trav->next != NULL)
    {
        if (trav->next->val == val)
        {
            trav->next = trav->next->next;
        }
        else
        {
            trav = trav->next;
        }
    }

    return head;
}
