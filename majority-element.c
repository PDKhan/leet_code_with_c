int majorityElement(int* nums, int numsSize) {
    int cnt = 0;
    int candidate;

    for(int i = 0; i < numsSize; i++){
        if(cnt == 0)
            candidate = nums[i];
        
        if(candidate == nums[i])
            cnt++;
        else
            cnt--;
    }

    return candidate;
}
