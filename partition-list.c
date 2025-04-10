struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* small = NULL;
    struct ListNode* s_tail;
    struct ListNode* big = NULL;
    struct ListNode* b_tail;
    struct ListNode* curr = head;

    if(head == NULL)
        return head;

    while(curr){
        struct ListNode* next = curr->next;

        curr->next = NULL;

        if(curr->val < x){
            if(small == NULL){
                small = curr;
                s_tail = small;
            }else{
                s_tail->next = curr;
                s_tail = s_tail->next;
            }
        }else{
            if(big == NULL){
                big = curr;
                b_tail = big;
            }else{
                b_tail->next = curr;
                b_tail = b_tail->next;
            }
        }

        curr = next;
    }

    if(small == NULL)
        return big;

    s_tail->next = big;

    return small;
}
