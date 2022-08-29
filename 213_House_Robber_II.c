#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a > b ? a : b)

int rob(int* nums, int numsSize)
{
    if(numsSize <= 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return max(nums[0],nums[1]);
    
    int dp1[numsSize];
    int dp2[numsSize];
    
    dp1[0] = nums[0];
    dp1[1] = max(nums[0],nums[1]);
    for(int i = 2; i < numsSize - 1; i++)
        dp1[i] = max(dp1[i - 1],dp1[i - 2] + nums[i]);
    
    dp2[1] = nums[1];
    dp2[2] = max(nums[1],nums[2]);
    for(int j = 3; j < numsSize; j ++)
        dp2[j] = max(dp2[j - 1],dp2[j - 2] + nums[j]);
    
    return max(dp1[numsSize - 2],dp2[numsSize - 1]);
}
