/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* next = node->next;
    while(node != NULL) {
        if(next->next == NULL) {
            node->val = next->val;
            node->next = NULL;
            break;
        } else {
            node->val = next->val;
            next = next->next;
            node = node->next;
        }
    }
}