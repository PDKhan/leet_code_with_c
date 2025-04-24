void reorderList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;

    while(curr){
        struct ListNode* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    slow->next = NULL;

    struct ListNode* first = head;
    struct ListNode* second = prev;

    while(first && second){
        struct ListNode* next1 = first->next;
        struct ListNode* next2 = second->next;

        first->next = second;
        second->next = next1;

        first = next1;
        second = next2;
    }
}
