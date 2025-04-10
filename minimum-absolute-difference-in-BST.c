void search(struct TreeNode* root, struct TreeNode** prev, int* result){
    if(root == NULL)
        return;

    search(root->left, prev, result);
    
    if(*prev){
        int diff = abs(root->val - (*prev)->val);

        if(diff < *result)
            *result = diff;
    }

    *prev = root;

    search(root->right, prev, result);
}

int getMinimumDifference(struct TreeNode* root) {
    int result = INT_MAX;
    struct TreeNode* prev = NULL;

    search(root, &prev, &result);

    return result;
}
