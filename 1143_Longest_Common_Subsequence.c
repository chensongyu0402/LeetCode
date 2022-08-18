#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a > b ? a : b)

int longestCommonSubsequence(char * text1, char * text2)
{
    int len1 = strlen(text1), len2 = strlen(text2);
    int dp[1001][1001] = {0};
    for(int i = 0; i < len1; i ++) {
        for(int j = 0 ; j < len2; j++) {
            if(text1[i] == text2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);
        }
    }
    return dp[len1][len2];
}