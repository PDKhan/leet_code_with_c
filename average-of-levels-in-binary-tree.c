double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    int front = 0, rear = 0;
    struct TreeNode* q[100000];
    double* result = (double*)malloc(100000*sizeof(double));

    *returnSize = 0;
    q[rear++] = root;

    while(front != rear){
        double sum = 0;
        int len = rear - front;

        for(int i = 0; i< len; i++){
            struct TreeNode* curr = q[front++];

            if(curr->left)
                q[rear++] = curr->left;
            
            if(curr->right)
                q[rear++] = curr->right;
            
            sum += curr->val;
        }

        result[(*returnSize)++] = sum / len;
    }

    return result;
}
