char* longestCommonPrefix(char** strs, int strsSize) {
    int i, pos = 0;
    char* result = (char*)calloc(201, 1);

    while(strs[0][pos]){
        char ch = strs[0][pos];

        for(i = 1; i < strsSize; i++){
            if(strs[i][pos] != ch)
                return result;
        }

        result[pos++] = ch;
    }

    return result;
}
