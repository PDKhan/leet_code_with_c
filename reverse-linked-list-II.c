struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    int i = 1;
    int top = 0;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* stack[500];

    while(curr){
        struct ListNode* next = curr->next;

        curr->next = NULL;

        if(left <= i && i < right){
            stack[top++] = curr;
        }else if(i == right){
            if(prev == NULL){
                prev = curr;
                head = prev;
            }else{
                prev->next = curr;
                prev = prev->next;
            }

            while(top){
                    prev->next = stack[--top];
                    prev = prev->next;
            }
        }else{
            if(prev == NULL){
                prev = curr;
            }else{
                prev->next = curr;
                prev = prev->next;
            }
        }

        i++;
        curr = next;
    }

    return head;
}
