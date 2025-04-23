struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL;
    struct ListNode* tail;

    if(listsSize == 0)
        return NULL;
    
    while(1){
        int min = -1;

        for(int i = 0; i < listsSize; i++){
            if(lists[i]){
                if(min == -1 || lists[i]->val < lists[min]->val)
                    min = i;
            }
        }

        if(min == -1)
            break;

        if(head == NULL){
            head = lists[min];
            tail = head;
        }else{
            tail->next = lists[min];
            tail = tail->next;
        }

        lists[min] = lists[min]->next;
        tail->next = NULL;
    }

    return head;
}
