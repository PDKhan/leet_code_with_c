int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = NULL;
    int front = 0, rear = 0;
    struct TreeNode* q[100];

    *returnSize = 0;

    if(root == NULL)
        return result;

    result = (int*)malloc(100 * sizeof(int));

    q[rear++] = root;

    while(front != rear){
        int val;
        int len = rear - front;

        for(int i = 0; i < len; i++){
            struct TreeNode* curr = q[front++];

            if(curr->left)
                q[rear++] = curr->left;
            
            if(curr->right)
                q[rear++] = curr->right;
            
            val = curr->val;
        }

        result[(*returnSize)++] = val;
    }

    return result;
}
