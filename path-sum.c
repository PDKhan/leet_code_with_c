bool search(struct TreeNode* root, int sum, int targetSum){
    if(root == NULL)
        return false;

    if(root->left == NULL && root->right == NULL){
        if(sum + root->val == targetSum)
            return true;
        else
            return false;
    }

    return search(root->left, sum + root->val, targetSum) || search(root->right, sum + root->val, targetSum);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return search(root, 0, targetSum);
}
