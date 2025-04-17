int countSubstrings(char* s) {
    int len = strlen(s);
    int cnt = 0;

    for(int i = 0; i < len; i++){
        int start = i;
        int end = i;

        while(0 <= start && end < len && s[start] == s[end]){
            cnt++;
            start--;
            end++;
        }

        start = i;
        end = i+1;

        while(0 <= start && end < len && s[start] == s[end]){
            cnt++;
            start--;
            end++;
        }
    }

    return cnt;
}
