/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b){
    char* x = (char*)a;
    char* y = (char*)b;

    return *x - *y;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char* sorted_strs[strsSize];
    int group[strsSize];

    for(int i = 0; i < strsSize; i++){
        sorted_strs[i] = strdup(strs[i]);

        qsort(sorted_strs[i], strlen(strs[i]), sizeof(char), cmp);
    }

    memset(group, 0, strsSize * sizeof(int));
    int g = 1;
    for(int i = 0; i < strsSize; i++){
        if(group[i] != 0)
            continue;
        
        group[i] = g;

        for(int j = i + 1; j < strsSize; j++){
            if(group[j])
                continue;
            
            if(strcmp(sorted_strs[i], sorted_strs[j]) == 0)
                group[j] = g;
        }

        g++;
    }

    *returnSize = g - 1;
    *returnColumnSizes = (int*)malloc((g - 1) * sizeof(int));
    memset((*returnColumnSizes), 0, (g - 1) * sizeof(int));
    char*** result = (char***)malloc((g - 1) * sizeof(char**));

    for(int i = 0; i < g - 1; i++)
        result[i] = (char**)malloc(strsSize * sizeof(char*));

    for(int i = 0; i < strsSize; i++){
        int idx = group[i] - 1;

        result[idx][(*returnColumnSizes)[idx]++] = strdup(strs[i]);
    }

    for(int i = 0; i < strsSize; i++){
        free(sorted_strs[i]);
    }

    return result;
}
