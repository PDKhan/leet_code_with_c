struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* first = head;
    struct ListNode* second = head;
    struct ListNode* prev = NULL;

    for(int i = 0; i < n; i++)
        first = first->next;
    
    while(first){
        if(prev == NULL)
            prev = second;
        else
            prev = prev->next;
        
        second = second->next;
        first = first->next;
    }

    if(prev == NULL){
        head = second->next;
        free(second);
    }else{
        prev->next = second->next;
        free(second);
    }

    return head;
}
