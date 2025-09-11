typedef struct Node{
    bool isEnd;
    struct Node* children[26];
}Node;

typedef struct {
    Node* root;
} WordDictionary;

Node* create_node(){
    Node* node = (Node*)malloc(sizeof(Node));
    node->isEnd = false;
    for(int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

WordDictionary* wordDictionaryCreate() {
    WordDictionary* dic = (WordDictionary*)malloc(sizeof(WordDictionary));

    dic->root = create_node();
    return dic;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    Node* node = obj->root;

    for(int i = 0; word[i] != '\0'; i++){
        int idx = word[i] - 'a';

        if(!node->children[idx])
            node->children[idx] = create_node();
        node = node->children[idx];
    }

    node->isEnd = true;
}

bool dfs(Node* node, int pos, char* word){
    if(word[pos] == '\0')
        return node->isEnd;
    
    char ch = word[pos];
    int idx = ch - 'a';

    if(ch != '.'){
        if(!node->children[idx])
            return false;
        return dfs(node->children[idx], pos + 1, word);
    }

    for(int i = 0; i < 26; i++){
        if(node->children[i]){
            if(dfs(node->children[i], pos + 1, word))
                return true;
        }
    }

    return false;
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return dfs(obj->root, 0, word);
}

void free_children(Node* node){
    for(int i = 0; i < 26; i++){
        if(node->children[i])
            free_children(node->children[i]);
    }

    free(node);
}
void wordDictionaryFree(WordDictionary* obj) {
    free_children(obj->root);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
