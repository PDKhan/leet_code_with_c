/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int* result){
    if(root == NULL)
        return;
    
    dfs(root->left, result);

    (*result)++;

    dfs(root->right, result);
}

int countNodes(struct TreeNode* root) {
    int result = 0;

    dfs(root, &result);

    return result;
}