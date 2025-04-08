struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* new_head = NULL;
    struct ListNode* tail;

    while(list1 || list2){
        struct ListNode* curr;

        if(list1 && list2){
            if(list1->val < list2->val){
                curr = list1;
                list1 = list1->next;
            }else{
                curr = list2;
                list2 = list2->next;
            }
        }else if(list1){
            curr = list1;
            list1 = list1->next;
        }else{
            curr = list2;
            list2 = list2->next;
        }

        if(new_head == NULL){
            new_head = curr;
            tail = new_head;
        }else{
            tail->next = curr;
            tail = tail->next;
        }

        curr->next = NULL;
    }

    return new_head;
}
