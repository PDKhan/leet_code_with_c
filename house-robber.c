int rob(int* nums, int numsSize) {
    int dp[numsSize + 3];
    
    dp[numsSize] = 0;
    dp[numsSize+1] = 0;
    dp[numsSize+2] = 0;

    for(int i = numsSize-1; i >= 0; i--){
        if(dp[i+3] > dp[i+2])
            dp[i] = nums[i] + dp[i+3];
        else
            dp[i] = nums[i] + dp[i+2];
    }

    if(dp[0] > dp[1])
        return dp[0];
    else
        return dp[1];
}
