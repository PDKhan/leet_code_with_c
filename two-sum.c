#define TABLE_SIZE 100003

int hash_idx(int val){
    return ((val % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int hash[TABLE_SIZE] = {0};
    int* result = (int*)malloc(2*sizeof(int));

    *returnSize = 2;

    for(int i = 0; i < numsSize; i++){
        int val = target - nums[i];

        if(hash[hash_idx(val)]){
            result[0] = hash[hash_idx(val)] - 1;
            result[1] = i;
            break;
        }

        hash[hash_idx(nums[i])] = i + 1;
    }

    return result;
}
