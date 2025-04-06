int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize - 1;

    if(numsSize == 0)
        return 0;
    
    if(numsSize == 1){
        if(nums[0] == val)
            return 0;
        else
            return 1;
    }

    while(left < right){
        while(left < numsSize && nums[left] != val)
            left++;
        
        while(right >= 0 && nums[right] == val)
            right--;

        if(left >= right)
            break;

        nums[left] = nums[right];
        nums[right] = val;
    }

    return left;
}