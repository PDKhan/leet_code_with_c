/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
#define MAX_SIZE 6000

struct Node* connect(struct Node* root) {
    int front = 0;
    int rear = 0;
	struct Node* q[MAX_SIZE];

    if(root == NULL)
        return NULL;

    q[rear++] = root;

    while(front != rear){
        int len = rear - front;
        struct Node* prev = NULL;

        for(int i = 0; i < len; i++){
            struct Node* curr = q[front++];

            if(curr->left)
                q[rear++] = curr->left;
            
            if(curr->right)
                q[rear++] = curr->right;
            
            if(prev)
                prev->next = curr;
            
            prev = curr;
        }

        prev->next = NULL;
    }

    return root;
}
