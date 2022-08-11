#include<stdio.h>
#include<stdlib.h>

int coinChange(int* coins, int coinsSize, int amount)
{
    if(amount == 0)
        return 0;
    int dp[10001] = {0};
    for(int i = 1; i <= amount; i++)
        dp[i] = INT_MAX - 1000;
    for(int i = 0; i < coinsSize; i++) {
        if(coins[i] > 10000)
            continue;
        else
            dp[coins[i]] = 1;
    }
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coinsSize; j++) {
            if(i - coins[j] < 0)
                continue;
            else
                dp[i] = dp[i - coins[j]] + 1 > dp[i] ? dp[i] : (dp[i - coins[j]] + 1);
        }
    }
    if(dp[amount] == INT_MAX - 1000)
        return -1;
    else
        return dp[amount];
}