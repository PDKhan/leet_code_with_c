int characterReplacement(char* s, int k) {
    int start = 0;
    int max_len = 0;
    int max_cnt = 0;
    int map[26] = {0};

    for(int end = 0; s[end] != '\0'; end++){
        map[s[end] - 'A']++;

        if(max_cnt < map[s[end] - 'A'])
            max_cnt = map[s[end] - 'A'];

        while(end - start + 1 - max_cnt > k){
            map[s[start] - 'A']--;
            start++;
        }

        if(max_len < end - start + 1)
            max_len = end - start + 1;
    }

    return max_len;
}
