int cmp(const void* a, const void* b){
    return *((int*)a) - *((int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;

    int result = 0;
    int tmp = 1;

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1] + 1)
            tmp++;
        else if(nums[i] == nums[i - 1])
            continue;
        else{
            result = fmax(tmp, result);
            tmp = 1;
        }
    }

    return fmax(tmp, result);
}
