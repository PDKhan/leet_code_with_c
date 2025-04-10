/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int len = 1;
    struct ListNode* tail = head;
    struct ListNode* new_head = NULL;
    struct ListNode* node = head;

    if(head == NULL || k == 0)
        return head;

    while(tail->next){
        tail = tail->next;
        len++;
    }

    k = k % len;

    if(k == 0)
        return head;

    for(int i = 0; i < len - k - 1; i++){
        node = node->next;
    }

    new_head = node->next;
    node->next = NULL;
    tail->next = head;

    return new_head;    
}
