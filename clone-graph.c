#define MAX_SIZE 101

struct Node* copy_node(struct Node* org){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->val = org->val;
    node->numNeighbors = org->numNeighbors;
    node->neighbors = (struct Node**)malloc(node->numNeighbors*sizeof(struct Node*));

    return node;
}

struct Node* dfs(struct Node* org, struct Node* map[MAX_SIZE][2]){
    if(org == NULL)
        return NULL;

    if(map[org->val][0])
        return map[org->val][1];
    
    struct Node* copy = copy_node(org);
    map[org->val][0] = org;
    map[org->val][1] = copy;

    for(int i = 0; i < org->numNeighbors; i++)
        copy->neighbors[i] = dfs(org->neighbors[i], map);

    return copy;
}

struct Node *cloneGraph(struct Node *s) {
    struct Node* map[MAX_SIZE][2] = {0};

	return dfs(s, map);
}
