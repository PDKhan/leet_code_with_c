int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}
