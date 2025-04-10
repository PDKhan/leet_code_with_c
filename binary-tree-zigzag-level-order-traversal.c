#define MAX_SIZE 2001

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if(root == NULL)
        return NULL;

    int front = 0, rear = 0;
    struct TreeNode* q[MAX_SIZE];
    int** result = (int**)malloc(MAX_SIZE*sizeof(int*));

    *returnColumnSizes = (int*)malloc(MAX_SIZE*sizeof(int));

    q[rear++] = root;

    while(front != rear){
        int len = rear - front;

        result[*returnSize] = (int*)malloc(len*sizeof(int));
        if((*returnSize) % 2)
            (*returnColumnSizes)[*returnSize] = len;
        else
            (*returnColumnSizes)[*returnSize] = 0;

        for(int i = 0; i < len; i++){
            struct TreeNode* curr = q[front++];

            if((*returnSize) % 2)
                result[*returnSize][len-i-1] = curr->val;
            else
                result[*returnSize][((*returnColumnSizes)[*returnSize])++] = curr->val;

            if(curr->left)
                q[rear++] = curr->left;
            
            if(curr->right)
                q[rear++] = curr->right;
        }

        (*returnSize)++;
    }

    return result;
}
