int removeDuplicates(int* nums, int numsSize) {
    int index = 1;

    for(int i = 1; i < numsSize; i++){
        if(nums[index-1] != nums[i])
            nums[index++] = nums[i];
    }

    return index;
}
