/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    int cnt = 1;
    struct ListNode* r_head = NULL;
    struct ListNode* r_tail;
    struct ListNode* new_head = NULL;
    struct ListNode* tail;
    struct ListNode* search = head;

    while(search){
        struct ListNode* next = search->next;

        search->next = NULL;

        if(cnt >= left && cnt <= right){
            search->next = r_head;
            r_head = search;

            if(cnt == left)
                r_tail = r_head;

            if(cnt == right){
                if(new_head == NULL)
                    new_head = r_head;
                else
                    tail->next = r_head;
                tail = r_tail;
            }
        }else{
            if(new_head == NULL){
                new_head = search;
                tail = new_head;
            }else{
                tail->next = search;
                tail = tail->next;
            }
        }

        cnt++;
        search = next;
    }

    if(new_head)
        return new_head;
    else
        return r_head;
}