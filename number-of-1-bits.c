int hammingWeight(int n) {
    int result = 0;

    while(n){
        if(n & 1)
            result++;
        
        n /= 2;
    }

    return result;
}
