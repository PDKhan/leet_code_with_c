typedef struct Node{
    char* str;
    int cnt;
}Node;

int cmp(char* a, char* b){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        if(a[i] != b[i])
            cnt++;
    }

    return cnt;
}

int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    if(cmp(startGene, endGene) == 0)
        return 0;

    int cnt = 0;
    for(int i = 0; i < bankSize; i++){
        if(cmp(endGene, bank[i]) == 0){
            cnt++;
            break;
        }
    }

    if(cnt == 0)
        return -1;

    int front = 0, rear = 0;
    Node* q = (Node*)malloc((bankSize + 1) * sizeof(Node));
    int* visited = (int*)malloc(bankSize * sizeof(int));
    memset(visited, 0, bankSize * sizeof(int));
    q[rear++] = (Node){startGene, 0};

    while(front != rear){
        Node curr = q[front++];

        if(cmp(curr.str, endGene) == 0){
            free(q);
            free(visited);
            return curr.cnt;
        }
        
        for(int i = 0; i < bankSize; i++){
            if(cmp(curr.str, bank[i]) == 1){
                if(visited[i])
                    continue;
                
                visited[i] = 1;
                q[rear++] = (Node){bank[i], curr.cnt + 1};
            }
        }
    }

    free(q);
    free(visited);
    return -1;
}
