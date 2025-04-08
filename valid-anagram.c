bool isAnagram(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int hash[26] = {0};

    if(slen != tlen)
        return false;

    for(int i = 0; i < slen; i++){
        hash[s[i] - 'a']++;
    }

    for(int i = 0; i < tlen; i++){
        if(hash[t[i] - 'a'] == 0)
            return false;
        
        hash[t[i] - 'a']--;
    }

    return true;
}
