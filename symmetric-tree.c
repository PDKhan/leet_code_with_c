bool search(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL && right == NULL)
        return true;
    else if(left == NULL)
        return false;
    else if(right == NULL)
        return false;
    else if(left->val != right->val)
        return false;
    
    return search(left->left, right->right) && search(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;
    
    return search(root->left, root->right);
}