int maxDepth(struct TreeNode* root) {
    int depth = 0;
    int first = 0, last = 0;
    struct TreeNode* q[100000];

    if(root == NULL)
        return depth;

    q[last++] = root;

    while(first != last){
        int len = last - first;

        for(int i = 0; i < len; i++){
            struct TreeNode* curr = q[first++];

            if(curr->left)
                q[last++] = curr->left;
            
            if(curr->right)
                q[last++] = curr->right;
        }

        depth++;
    }

    return depth;
}
