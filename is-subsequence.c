bool isSubsequence(char* s, char* t) {
    int pos = 0;

    for(int i = 0; t[i] != '\0'; i++){
        if(t[i] == s[pos])
            pos++;
    }

    return s[pos] == '\0';
}
