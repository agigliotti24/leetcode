

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void printList(struct ListNode *head) {
    while(head != NULL) {
        if (head->next == NULL)
            printf("%d", head->val);
        else
            printf("%d, ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    struct ListNode* res = NULL;

    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    if(left->val < right->val) {
        res = left;
        res->next = merge(left->next, right);
    } else {
        res = right;
        res->next = merge(left, right->next);
    }

    return res;
}

void split(struct ListNode** head) {
    if(*head == NULL || (*head)->next == NULL)
        return;
    
    // Find mid point of linked list
    struct ListNode *q = *head;
    int count = 0;
    while(q != NULL){
        ++count;
        q = q->next;
    }
    int mid = count/2;

    // Split into left and right linked lists
    q = *head;
    struct ListNode *left = *head;
    struct ListNode *right = *head;
    for(int i = 0; i < mid-1; ++i)
        q = q->next;
    right = q->next;
    q->next = NULL;

    split(&left);
    split(&right);

    *head = merge(left, right);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    // Merge the two lists and then sort like normal using merge sort?

    // Merge lists
    struct ListNode *q = list1;
    while(q->next != NULL)
        q = q->next;
    q->next = list2;

    split(&list1);

    return list1;
}
