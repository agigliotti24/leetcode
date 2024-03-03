/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recursiveFunc(ListNode *head) {
        if(head == NULL)
            return NULL;

        ListNode *newHead = head;

        if(head->next != NULL){
            newHead = recursiveFunc(head->next);
            head->next->next = head;
        }
        head->next = NULL;

        return newHead;
    }

    ListNode* iterativeFunc(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *tmp = NULL;

        while(cur != NULL) {
            tmp = cur->next;
            cur->next = prev;

            prev = cur;
            cur = tmp;
        }

        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *res = NULL;

        // res = recursiveFunc(head);
        res = iterativeFunc(head);

        return res;
    }
};