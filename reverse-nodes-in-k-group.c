/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int cnt = 1;
    int top = 0;
    struct ListNode* stack[k];
    struct ListNode* new_head = NULL;
    struct ListNode* tail;
    struct ListNode* search = head;

    while(search){
        struct ListNode* next = search->next;

        search->next = NULL;

        stack[top++] = search;

        if(cnt == k){
            while(top){
                struct ListNode* node = stack[--top];
                if(new_head == NULL){
                    new_head = node;
                    tail = new_head;
                }else{
                    tail->next = node;
                    tail = tail->next;
                }
            }

            cnt = 0;
        }

        cnt++;
        search = next;
    }

    for(int i = 0; i < top; i++){
        tail->next = stack[i];
        tail = tail->next;
    }

    return new_head;
}
