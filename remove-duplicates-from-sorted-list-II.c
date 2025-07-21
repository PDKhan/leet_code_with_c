/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    struct ListNode* left = head;

    while(left){
        int cnt = 0;
        struct ListNode* right = left->next;

        while(right && left->val == right->val){
            cnt++;
            right = right->next;
        }
        
        if(cnt == 0){
            tail->next = left;
            tail = tail->next;
        }

        left->next = NULL;
        left = right;
    }

    return dummy.next;
}
