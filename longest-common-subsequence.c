int longestCommonSubsequence(char* text1, char* text2) {
    int t1_len = strlen(text1);
    int t2_len = strlen(text2);
    int dp[t1_len+1][t2_len+1];

    for(int i = 0; i <= t1_len; i++)
        memset(dp[i], 0, (t2_len + 1) * sizeof(int));
    
    for(int i = 1; i <= t1_len; i++){
        for(int j = 1; j <= t2_len; j++){
            if(text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if(dp[i - 1][j] > dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[t1_len][t2_len];
}
