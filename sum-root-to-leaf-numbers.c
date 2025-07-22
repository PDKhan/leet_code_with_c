/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void search(struct TreeNode* root, int* total, int sum){
    if(root->left == NULL && root->right == NULL)
        (*total) += root->val + (sum * 10);
    else{
        if(root->left)
            search(root->left, total, root->val + (sum * 10));
        
        if(root->right)
            search(root->right, total, root->val + (sum * 10));
    }
}

int sumNumbers(struct TreeNode* root) {
    int total = 0;

    search(root, &total, 0);

    return total;
}
