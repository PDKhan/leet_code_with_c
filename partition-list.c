struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode l_dummy;
    struct ListNode* l_tail = &l_dummy;
    struct ListNode h_dummy;
    struct ListNode* h_tail = &h_dummy;
    struct ListNode* node = head;

    while(node){
        struct ListNode* next = node->next;

        node->next = NULL;

        if(node->val < x){
            l_tail->next = node;
            l_tail = l_tail->next;
        }else{
            h_tail->next = node;
            h_tail = h_tail->next;
        }

        node = next;
    }

    l_tail->next = h_dummy.next;

    return l_dummy.next;
}
