/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int product = 1;
    int* result = (int*)malloc(sizeof(int)*numsSize);

    *returnSize = numsSize;

    for(int i = 0; i < numsSize; i++){
        result[i] = product;

        product *= nums[i];
    }

    product = 1;

    for(int i = numsSize - 1; i >= 0; i--){
        result[i] *= product;

        product *= nums[i];
    }

    return result;
}
