#define MAX_LEN 6001

struct TreeNode* build(int* inorder, int start, int end, int* table, int* postorder, int* pos){
    if(start >= end)
        return NULL;
    
    int idx = postorder[*pos] + 3000;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = postorder[(*pos)--];

    root->right = build(inorder, table[idx] + 1, end, table, postorder, pos);
    root->left = build(inorder, start, table[idx], table, postorder, pos);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int pos = postorderSize - 1;
    int table[MAX_LEN] = {0};

    for(int i = 0; i < inorderSize; i++)
        table[inorder[i] + 3000] = i;

    return build(inorder, 0, inorderSize, table, postorder, &pos);
}
