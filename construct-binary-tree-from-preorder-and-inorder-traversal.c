#define MAX_VAL 6001

struct TreeNode* createNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode* build(int* preorder, int* pos, int* table, int* inorder, int start, int end){
    if(start >= end)
        return NULL;

    int val = preorder[(*pos)++];
    struct TreeNode* root = createNode(val);

    root->left = build(preorder, pos, table, inorder, start, table[val+3000]);
    root->right = build(preorder, pos, table, inorder, table[val+3000]+1, end);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int pos = 0;
    int table[MAX_VAL] = {0};

    for(int i = 0; i < inorderSize; i++)
        table[inorder[i]+3000] = i;
    
    return build(preorder, &pos, table, inorder, 0, inorderSize);
}
