bool isIsomorphic(char* s, char* t) {
    int i;
    int s_hash[128] = {0};
    int t_hash[128] = {0};

    for(i = 0; s[i] != '\0'; i++){
        if(s_hash[s[i]] == 0)
            s_hash[s[i]] = t[i];
        else if(s_hash[s[i]] != t[i])
            return false;
        
        if(t_hash[t[i]] == 0)
            t_hash[t[i]] = s[i];
        else if(t_hash[t[i]] != s[i])
            return false;
    }

    return true;
}
