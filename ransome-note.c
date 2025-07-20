bool canConstruct(char* ransomNote, char* magazine) {
    int hash[26] = {0};

    for(int i = 0; magazine[i] != '\0'; i++){
        hash[magazine[i] - 'a']++;
    }

    for(int i = 0; ransomNote[i] != '\0'; i++){
        if(hash[ransomNote[i] - 'a'] == 0)
            return false;
        
        hash[ransomNote[i] - 'a']--;
    }

    return true;
}
