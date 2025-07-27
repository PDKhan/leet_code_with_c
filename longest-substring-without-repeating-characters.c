int lengthOfLongestSubstring(char* s) {
    int map[128] = {0};
    int start = 0;
    int result = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(map[s[i]] > start){
            start = map[s[i]];
        }

        result = i - start + 1 > result ? i - start + 1 : result;
        map[s[i]] = i + 1;
    }

    return result;
}
