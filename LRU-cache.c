#define MAX_SIZE 100000

typedef struct Node{
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct {
    int capacity;
    int size;
    Node* hash[MAX_SIZE];
    Node* head;
    Node* tail;
} LRUCache;

Node* create_node(int key, int value){
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));

    cache->capacity = capacity;
    cache->size = 0;
    cache->head = create_node(-1, -1);
    cache->tail = create_node(-1, -1);

    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    memset(cache->hash, 0, MAX_SIZE*sizeof(Node*));

    return cache;
}

void move_to_head(LRUCache* obj, Node* node){
    if(obj->head->next == node)
        return;

    if(node->prev)
        node->prev->next = node->next;
    
    if(node->next)
        node->next->prev = node->prev;

    obj->head->next->prev = node;
    node->next = obj->head->next;
    obj->head->next = node;
    node->prev = obj->head;
}

void remove_tail(LRUCache* obj){
    Node* node = obj->tail->prev;

    node->prev->next = obj->tail;
    obj->tail->prev = node->prev;

    obj->hash[node->key] = NULL;

    free(node);
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = obj->hash[key];

    if(node == NULL)
        return -1;
    else{
        move_to_head(obj, node);
        return node->value;
    }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = obj->hash[key];

    if(node){
        node->value = value;

        move_to_head(obj, node);
    }else{
        node = create_node(key, value);

        obj->hash[key] = node;

        move_to_head(obj, node);

        if(obj->size == obj->capacity){
            remove_tail(obj);
        }else
            obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* node = obj->head;

    while(node){
        Node* next = node->next;

        free(node);
        node = next;
    }

    free(obj);
}
