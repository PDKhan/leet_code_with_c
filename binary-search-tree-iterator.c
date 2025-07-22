/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_SIZE 1000

typedef struct {
    int top;
    struct TreeNode* stack[MAX_SIZE];    
} BSTIterator;

void push_left(struct TreeNode* node, BSTIterator* itr){
    while(node){
        itr->stack[itr->top++] = node;
        node = node->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* itr = (BSTIterator*)malloc(sizeof(BSTIterator));

    itr->top = 0;

    push_left(root, itr);

    return itr;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = obj->stack[--obj->top];

    if(node->right)
        push_left(node->right, obj);
    
    return node->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top > 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}