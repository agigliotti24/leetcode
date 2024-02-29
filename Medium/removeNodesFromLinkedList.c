/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode *prev = head;
    struct ListNode *cur = head;
    struct ListNode *q = head;
    bool remove = false;

    // Find length of linked list
    int count = 0;
    while(q != NULL) {
        ++count;
        q = q->next;
    }

    // Create array of items
    int array[count][2];
    q = head;
    count = 0;
    while(q != NULL) {
        array[count][1] = 0;
        array[count++][0] = q->val;
        q = q->next;
    }

    // Iterate array backwards to determine if any item should be deleted
    int max = array[count-1][0];
    for(int i = count-1; i >= 0; --i) {
        if(array[i][0] < max)
            array[i][1] = 1;
        if(array[i][0] > max)
            max = array[i][0];
    }

    // Iterate over array and remove nodes when you reach one that is flagged for removal
    for(int i = 0; i < count; i++) {
        if(cur == NULL)
            break;

        // Remove node
        if(array[i][1]) {
            // Remove head
            if(head == cur) {
                head = head->next;
                prev = head;
                cur = head;
            } else {
                prev->next = cur->next;
                cur = prev->next;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}