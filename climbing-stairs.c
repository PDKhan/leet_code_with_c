int climbStairs(int n) {
    int prev1 = 0;
    int prev2 = 0;
    int curr = 1;

    for(int i = 0; i < n; i++){
        prev2 = prev1;
        prev1 = curr;
        curr = prev1 + prev2;
    }

    return curr;
}
