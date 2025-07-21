/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* create_node(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

    node->val = val;
    node->next = NULL;

    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* head = NULL;
    struct ListNode* tail;

    while(l1 || l2 || carry){
        if(l1){
            carry += l1->val;
            l1 = l1->next;
        }

        if(l2){
            carry += l2->val;
            l2 = l2->next;
        }

        if(head == NULL){
            head = create_node(carry % 10);
            tail = head;
        }else{
            tail->next = create_node(carry % 10);
            tail = tail->next;
        }

        carry /= 10;
    }

    return head;
}