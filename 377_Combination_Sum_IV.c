#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) 
{
    int n1 = *((int*)a);
    int n2 = *((int*)b);
    return n1 - n2;
}

int combinationSum4(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), compare);
    unsigned *dp = calloc(target + 1, sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > target)
            break;
        else
            dp[nums[i]] = 1;
    }
    
    for(int i = 1; i <= target; i++) {
        for(int j = 0; j < numsSize; j++) {
            if(nums[j] <= i)
                dp[i] += dp[i - nums[j]];
            }
    }
    
    return dp[target];
}
