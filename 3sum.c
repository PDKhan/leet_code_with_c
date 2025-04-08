int cmp(const void* a, const void* b){
    return *((int*)a) - *((int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(numsSize*numsSize*sizeof(int*));

    *returnSize = 0;

    *returnColumnSizes = (int*)malloc(numsSize*numsSize*sizeof(int));    

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 2; i++){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0){
                result[*returnSize] = (int*)malloc(3*sizeof(int));
                (*returnColumnSizes)[*returnSize] = 3;
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;

                while(left < right && nums[left] == nums[left+1])
                    left++;

                while(left < right && nums[right] == nums[right-1])
                    right--;
                
                left++;
                right--;
            }else if(sum < 0)
                left++;
            else
                right--;
        }
    }

    return result;
}
