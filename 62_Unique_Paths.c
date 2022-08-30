#include<stdio.h>
#include<stdlib.h>

int uniquePaths(int m, int n)
{
    int **dp = malloc(sizeof(int *) * m);
    for(int i = 0; i < m ; i ++)
        dp[i] = malloc(sizeof(int) * n);
    
    for(int i = 0; i < m; i++)
        dp[i][0] = 1;
    for(int i = 0; i < n; i++)
        dp[0][i] = 1;
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    
    int ans = dp[m - 1][n - 1];
    for(int i; i < m; i++)
        free(dp[i]);
    free(dp);
    return ans;
}