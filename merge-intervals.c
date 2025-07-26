/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b){
    int* x = *(int**)a;
    int* y = *(int**)b;

    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(intervalsSize * sizeof(int*));

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    result[*returnSize] = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[*returnSize] = 2;
    result[*returnSize][0] = intervals[0][0];
    result[*returnSize][1] = intervals[0][1];
    (*returnSize)++;

    for(int i = 1; i < intervalsSize; i++){
        if(result[*returnSize - 1][1] >= intervals[i][0]){
            if(result[*returnSize - 1][1] < intervals[i][1])
                result[*returnSize - 1][1] = intervals[i][1];
        }else{
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 2;
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
    }

    return result;
}
