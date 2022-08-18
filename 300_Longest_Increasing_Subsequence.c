#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a > b ? a : b)

int lengthOfLIS(int* nums, int numsSize) {
 
    if (numsSize <= 1)
        return numsSize;
    
    int maxRes = 1, dp[numsSize]; // dp[i] means the LIS with end of value nums[i]
    dp[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if (maxRes < dp[i])
            maxRes = dp[i];
    }
    
    return maxRes;
}