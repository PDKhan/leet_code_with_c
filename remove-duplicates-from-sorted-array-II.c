int removeDuplicates(int* nums, int numsSize) {
    if(numsSize <= 2)
        return numsSize;

    int pos = 2;

    for(int i = 2; i < numsSize; i++){
        if(nums[i] != nums[pos - 2])
            nums[pos++] = nums[i];
    }

    return pos;
}
