struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* new_head = NULL;
    struct ListNode* tail;
    int sum = 0;

    while(l1 || l2 || sum){
        if(l1 && l2){
            sum += l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }else if(l1){
            sum += l1->val;
            l1 = l1->next;
        }else if(l2){
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

        node->val = sum % 10;
        node->next = NULL;

        if(new_head == NULL){
            new_head = node;

            tail = new_head;
        }else{
            tail->next = node;
            tail = tail->next;
        }

        sum /= 10;
    }

    return new_head;
}
