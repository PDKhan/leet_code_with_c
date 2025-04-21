char* minWindow(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int t_map[128] = {0};
    int window[128] = {0};
    int min_low = 0;
    int min_len = INT_MAX;
    int need = 0;
    int match = 0;
    int low = 0;
    char* result = NULL;

    for(int i = 0; i < tlen; i++){
        if(t_map[t[i]] == 0)
            need++;

        t_map[t[i]]++;
    }

    for(int high = 0; high < slen; high++){
        window[s[high]]++;

        if(window[s[high]] == t_map[s[high]])
            match++;

        while(need == match){
            if(high - low + 1 < min_len){
                min_low = low;
                min_len = high - low + 1;
            }

            window[s[low]]--;

            if(window[s[low]] < t_map[s[low]])
                match--;

            low++;
        }
    }

    if(min_len == INT_MAX){
        result = (char*)malloc(1);
        result[0] = 0;
    }else{
        result = (char*)malloc(min_len + 1);
        strncpy(result, s + min_low, min_len);
        result[min_len] = 0;
    }

    return result;
}
