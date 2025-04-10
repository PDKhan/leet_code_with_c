struct ListNode* deleteDuplicates(struct ListNode* head) {
    int cnt = 0;
    struct ListNode* new_head = NULL;
    struct ListNode* tail;
    struct ListNode* left = head;
    struct ListNode* right;

    if(head == NULL)
        return NULL;
    
    right = left->next;

    while(right){
        while(right && left->val == right->val){
            right = right->next;
            cnt++;
        }

        if(right == NULL)
            break;

        if(cnt == 0){
            if(new_head == NULL){
                new_head = left;
                tail = new_head;
            }else{
                tail->next = left;
                tail = tail->next;
            }
            
            left->next = NULL;
        }

        left = right;
        right = right->next;
        cnt = 0;
    }

    if(cnt == 0){
        if(new_head == NULL){
            new_head = left;
            tail = new_head;
        }else{
            tail->next = left;
            tail = tail->next;
        }
    }

    return new_head;
}
