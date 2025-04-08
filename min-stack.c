typedef struct Node{
    int val;
    int min;
    struct Node* next;
}Node;


typedef struct {
    Node* stack;
} MinStack;


MinStack* minStackCreate() {
    MinStack* st = (MinStack*)malloc(sizeof(MinStack));

    st->stack = NULL;

    return st;
}

void minStackPush(MinStack* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->val = val;
    node->next = obj->stack;

    if(obj->stack == NULL)
        node->min = val;
    else if(obj->stack->min > val)
        node->min = val;
    else
        node->min = obj->stack->min;

    obj->stack = node;
}

void minStackPop(MinStack* obj) {
    if(obj->stack == NULL)
        return;
    
    Node* node = obj->stack;

    obj->stack = node->next;

    free(node);
}

int minStackTop(MinStack* obj) {
    if(obj->stack == NULL)
        return INT_MIN;

    return obj->stack->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->stack->min;
}

void minStackFree(MinStack* obj) {
    Node* node = obj->stack;

    while(node){
        Node* next = node->next;

        free(node);
        node = next;
    }

    free(obj);
}
