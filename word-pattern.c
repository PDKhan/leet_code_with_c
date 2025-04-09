bool find_hash(char** hash, char* str){
    for(int i = 0; i < 26; i++){
        if(hash[i] && strcmp(str, hash[i]) == 0)
            return true;
    }

    return false;
}

void free_node(char** hash){
    for(int i = 0; i < 26; i++){
        if(hash[i])
            free(hash[i]);
    }
}

bool wordPattern(char* pattern, char* s) {
    char* hash[26] = {0};
    char* p = pattern;
    char* str = strtok(s, " ");

    while(str){
        int idx = *p - 'a';

        if(*p == 0){
            free_node(hash);
            return false;
        }else if(hash[idx]){
            if(strcmp(hash[idx], str)){
                free_node(hash);
                return false;
            }
        }else if(find_hash(hash, str)){
            free_node(hash);
            return false;
        }else
            hash[idx] = strdup(str);
        
        p++;

        str = strtok(NULL, " ");
    }

    free_node(hash);

    return *p == 0;
}
