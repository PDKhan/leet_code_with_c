int cmp(const void* a, const void* b){
    return *((int*)b) - *((int*)a);
}

int hIndex(int* citations, int citationsSize) {
    int i;

    qsort(citations, citationsSize, sizeof(int), cmp);

    for(i = 0; i < citationsSize; i++){
        if(citations[i] <= i)
            break;
    }

    return i;
}
