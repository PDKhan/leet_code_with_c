bool search(struct TreeNode* root, int k, int* idx, int* result){
    if(root == NULL)
        return false;
    
    if(search(root->left, k, idx, result) == true)
        return true;

    if(*idx == k){
        *result = root->val;
        return true;
    }
    
    (*idx)++;

    return search(root->right, k, idx, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int result = -1;
    int idx = 1;

    search(root, k, &idx, &result);

    return result;
}
