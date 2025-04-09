/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

 #define HASH_SIZE 10003

 struct Map{
     struct Node* org;
     struct Node* copy;
     struct Map* next;
 };
 
 int hash(struct Node* ptr){
     return ((unsigned long)ptr >> 3) % HASH_SIZE;
 }
 
 void insertMap(struct Map** table, struct Node* org, struct Node* copy){
     int idx = hash(org);
     struct Map* map = (struct Map*)malloc(sizeof(struct Map));
 
     map->org = org;
     map->copy = copy;
     map->next = table[idx];
     table[idx] = map;
 }
 
 struct Node* getMap(struct Map** table, struct Node* org){
     int idx = hash(org);
     struct Map* curr = table[idx];
 
     while(curr){
         if(curr->org == org)
             return curr->copy;
         curr = curr->next;
     }
 
     return NULL;
 }
 
 struct Node* copyRandomList(struct Node* head) {
     struct Node* curr = head;
     struct Node* new_head = NULL;
     struct Node* tail;
     struct Map* table[HASH_SIZE] = {0};
 
     while(curr){
         struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 
         node->val = curr->val;
         node->next = NULL;
         node->random = NULL;
 
         if(new_head == NULL){
             new_head = node;
             tail = new_head;
         }else{
             tail->next = node;
             tail = tail->next;
         }
 
         insertMap(table, curr, node);
 
         curr = curr->next;
     }
 
     curr = head;
     tail = new_head;
 
     while(curr){
         tail->random = getMap(table, curr->random);
         curr = curr->next;
         tail = tail->next;
     }
 
     return new_head;
 }
 