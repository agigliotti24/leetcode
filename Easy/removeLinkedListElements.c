/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* q = head;
    struct ListNode* prev = head;
    while(q != NULL) {
        if(q->val == val) {
            if(q == head) {
                head = head->next;
                prev = NULL;
                q = head;
            } else {
                prev->next = q->next;
                q = q->next;
            }
        } else {
            prev = q;
            q = q->next;
        }
    }

    return head;
}