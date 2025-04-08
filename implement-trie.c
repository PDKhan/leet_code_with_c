typedef struct Node{
    struct Node* children[26];
    bool isEnd;
}Node;


typedef struct {
    Node* root;
} Trie;

Node* createNode(){
    Node* node = (Node*)malloc(sizeof(Node));

    for(int i = 0; i < 26; i++){
       node->children[i] = NULL;
    }

    node->isEnd = false;

    return node;
}

Trie* trieCreate() {
    Trie* t = (Trie*)malloc(sizeof(Trie));

    t->root = createNode();

    return t;
}

void trieInsert(Trie* obj, char* word) {
    Node* node = obj->root;

    for(int i = 0; word[i] != '\0'; i++){
        int index = word[i] - 'a';

        if(node->children[index] == NULL){
            node->children[index] = createNode();
        }

        node = node->children[index];
    }

    node->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    Node* node = obj->root;

    for(int i = 0; word[i] != '\0'; i++){
        int index = word[i] - 'a';

        if(node->children[index] == NULL)
            return false;
        
        node = node->children[index];
    }

    return node->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Node* node = obj->root;

    for(int i = 0; prefix[i] != '\0'; i++){
        int index = prefix[i] - 'a';

        if(node->children[index] == NULL)
            return false;
        
        node = node->children[index];
    }

    return true;
}

void free_children(Node* node){
    for(int i = 0; i < 26; i++){
        if(node->children[i]){
            free_children(node->children[i]);
        }
    }

    free(node);
}

void trieFree(Trie* obj) {
    free_children(obj->root);

    free(obj);
}
