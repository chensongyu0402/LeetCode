#include<stdio.h>
#include<stdlib.h>

bool canPartition(int* nums, int numsSize)
{
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
        sum += nums[i];
    if(sum % 2 != 0)
        return false;
    
    sum /= 2;
    int *dp = calloc(sum+1, sizeof(int));
    dp[0] = 1;
    
    for(int i = 0; i < numsSize; i ++)
        for(int j = sum; j >= nums[i]; j--)
            dp[j] = dp[j] || dp[j - nums[i]];
    return dp[sum];
}