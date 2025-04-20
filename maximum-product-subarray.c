int maxProduct(int* nums, int numsSize) {
    int result = nums[0];
    int curr_min = nums[0];
    int curr_max = nums[0];

    for(int i = 1; i < numsSize; i++){
        int tmp_max = curr_max;

        curr_max = fmax(nums[i], fmax(curr_max * nums[i], curr_min * nums[i]));
        curr_min = fmin(nums[i], fmin(tmp_max * nums[i], curr_min * nums[i]));
       
        result = fmax(result, curr_max);
    }

    return result;
}
